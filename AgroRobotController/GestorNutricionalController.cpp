#pragma once
#include "GestorNutricionalController.h"
#include "AlmacenController.h"

using namespace System::Runtime::Serialization::Formatters::Binary;
using namespace System::IO;
using namespace AgroRobotController;
using namespace System::Collections::Generic;

GestorNutricionalController::GestorNutricionalController() {
	this->listaDietas = gcnew List<Dieta^>();
	this->listaAnimales = gcnew List<Animal^>();
	this->listaOrdenes = gcnew List<OrdenDistribucion^>();

	if (!File::Exists("animales.txt")) {
		File::WriteAllText("animales.txt", "");
	}

	if (!File::Exists("dietas.txt")) {
		File::WriteAllText("dietas.txt", "");
	}

	/*PARA ANIMALES*/
	array<String^>^ lineasAnimales = File::ReadAllLines("animales.txt");
	String^ separadores = ";";

	for each (String ^ linea in lineasAnimales) {
		if (String::IsNullOrEmpty(linea)) continue;

		array<String^>^ camposAnimales = linea->Split(separadores->ToCharArray());

		// --- VALIDACIÓN DE SEGURIDAD: Si la línea está incompleta, la saltamos ---
		if (camposAnimales->Length < 5) continue;

		/*campos obligatorios*/
		int idAnimal = Convert::ToInt32(camposAnimales[0]);
		String^ especie = camposAnimales[1];
		double peso = Convert::ToDouble(camposAnimales[2]);
		double edad = Convert::ToDouble(camposAnimales[3]);
		String^ estadoSalud = camposAnimales[4];

		// --- CORRECCIÓN: LECTURA SEGURA DE CAMPOS OPCIONALES ---
		// Usamos (condición) ? valor_si_verdadero : valor_si_falso

		String^ ultimaDieta = (camposAnimales->Length > 5) ? camposAnimales[5] : "Ninguna";

		String^ ultimaVezAlimentado = (camposAnimales->Length > 6) ? camposAnimales[6] : "No registrado";

		int vecesAlimentado = 0;
		if (camposAnimales->Length > 7) {
			try {
				vecesAlimentado = Convert::ToInt32(camposAnimales[7]);
			}
			catch (Exception^) { vecesAlimentado = 0; }
		}

		/*para que no haya error*/
		List<Muestra^>^ muestras = gcnew List<Muestra^>();
		Dieta^ dietaa = gcnew Dieta();
		List<HistoriaClinica^>^ historiasClinicas = gcnew List<HistoriaClinica^>();

		Animal^ animal = gcnew Animal(idAnimal, especie, peso, edad, estadoSalud, ultimaDieta, muestras, dietaa, historiasClinicas, ultimaVezAlimentado, vecesAlimentado);
		this->listaAnimales->Add(animal);
	}

	/*PARA DIETAS*/
	array<String^>^ lineasDietas = File::ReadAllLines("dietas.txt");
	for each (String ^ linea in lineasDietas) {
		if (String::IsNullOrEmpty(linea)) continue;

		array<String^>^ camposDietas = linea->Split(separadores->ToCharArray());
		/*campos obligatorios*/
		int id = Convert::ToInt32(camposDietas[0]);
		int idAnimal = Convert::ToInt32(camposDietas[1]);
		String^ fechaInicio = camposDietas[2];
		String^ alimentos = camposDietas[3];
		String^ frecuencia = camposDietas[4];
		/*para que no haya error*/
		List<OrdenDistribucion^>^ ordenesDistribucion = gcnew List<OrdenDistribucion^>();

		Dieta^ dieta = gcnew Dieta(id, idAnimal, fechaInicio, alimentos, frecuencia, ordenesDistribucion);
		this->listaDietas->Add(dieta);
	}
}

List<Animal^>^ GestorNutricionalController::obtenerTodosAnimales() {
	return this->listaAnimales;
}

void GestorNutricionalController::registrarAnimal(Animal^ animal) {
	if (!existeAnimal(animal->IdAnimal)) {
		this->listaAnimales->Add(animal);
		escribirArchivoAnimal();
	}
}

bool GestorNutricionalController::existeAnimal(int idAnimal) {
	return consultarAnimalporId(idAnimal) != nullptr;
}

Animal^ GestorNutricionalController::consultarAnimalporId(int idAnimal) {
	for each (Animal ^ animal in this->listaAnimales) {
		if (animal->IdAnimal == idAnimal) {
			return animal;
		}
	}
	return nullptr;
}

void GestorNutricionalController::escribirArchivoAnimal() {
	array <String^>^ lineasArchivoAnimales = gcnew array<String^>(this->listaAnimales->Count);
	for (int i=0;  i < this->listaAnimales->Count; i++) {
		Animal^ animal = this->listaAnimales[i];
		lineasArchivoAnimales[i] = animal->IdAnimal + ";" +
								   animal->Especie + ";" + 
								   animal->Peso + ";" + 
								   animal->Edad + ";" + 
								   animal->EstadoSalud + ";" + 
								   animal->UltimaDieta + ";" +
								   animal->UltimaVezAlimentado + ";" + 
								   animal->VecesAlimentado;
	}
	File::WriteAllLines("animales.txt", lineasArchivoAnimales);
}

List<Animal^>^ GestorNutricionalController::consultarAnimalporIdEspecie(int idAnimal, String^ especie) {
	List<Animal^>^ resultados = gcnew List<Animal^>();
	for each (Animal ^ animal in this->listaAnimales) {
		bool coincideId = (idAnimal == 0) || (animal->IdAnimal == idAnimal);
		bool coincideEspecie = String::IsNullOrEmpty(especie) || animal->Especie->Contains(especie);

		if (coincideId && coincideEspecie) {
			resultados->Add(animal);
		}
	}
	return resultados;
}

bool GestorNutricionalController::modificarAnimal(int idAnimal, String^ especie, double peso, double edad, String^ estadoSalud, String^ ultimaDieta) {
	Animal^ animal = consultarAnimalporId(idAnimal);
	if (animal != nullptr) {
		animal->Especie = especie;
		animal->Peso = peso;
		animal->Edad = edad;
		animal->EstadoSalud = estadoSalud;
		animal->UltimaDieta = ultimaDieta;
		escribirArchivoAnimal();
		return true;
	}
	return false;
}

void GestorNutricionalController::modificarUltimaAlimentacion(int id, String^ fecha) {
	Animal^ animal = consultarAnimalporId(id);
	if (animal != nullptr) {
		animal->UltimaVezAlimentado = fecha;
		animal->VecesAlimentado +=1;
	}
	escribirArchivoAnimal();
}

bool GestorNutricionalController::eliminarAnimal(int idAnimal) {
	Animal^ animal = consultarAnimalporId(idAnimal);
	if (animal != nullptr) {
		this->listaAnimales->Remove(animal);
		return true;
	}
	return false;
}

void GestorNutricionalController::closeAnimal() {
	this->listaAnimales = nullptr;
}

List<Dieta^>^ GestorNutricionalController::obtenerTodasDietas() {
	return this->listaDietas;
}

void GestorNutricionalController::registrarDieta(Dieta^ dieta) {
	if (!existeDieta(dieta->Id)) {
		this->listaDietas->Add(dieta);
		escribirArchivoDieta();
	}
}

bool GestorNutricionalController::existeDieta(int id) {
	return consultarDietaporId(id) != nullptr;
}

Dieta^ GestorNutricionalController::consultarDietaporId(int id) {
	if (this->listaDietas == nullptr) {
		this->listaDietas = gcnew List<Dieta^>();
	}

	for each (Dieta ^ dieta in this->listaDietas) {
		if (dieta->Id == id) {
			return dieta;
		}
	}
	return nullptr;
}

void GestorNutricionalController::escribirArchivoDieta() {
	array <String^>^ lineasArchivoDietas = gcnew array<String^>(this->listaDietas->Count);
	for (int i = 0; i < this->listaDietas->Count; i++) {
		Dieta^ dieta = this->listaDietas[i];
		lineasArchivoDietas[i] = dieta->Id + ";" +
								 dieta->IdAnimal + ";" +
								 dieta->FechaInicio + ";" +
								 dieta->Alimentos + ";" +
								 dieta->Frecuencia;
	}
	File::WriteAllLines("dietas.txt", lineasArchivoDietas);
}

bool GestorNutricionalController::modificarDieta(int id, int idAnimal, String^ fechaInicio, String^ alimentos, String^ frecuencia) {
	Dieta^ dieta = consultarDietaporId(id);
	if (dieta != nullptr) {
		dieta->IdAnimal = idAnimal;
		dieta->FechaInicio = fechaInicio;
		dieta->Alimentos = alimentos;
		dieta->Frecuencia = frecuencia;
		escribirArchivoDieta();
		return true;
	}
	return false;
}

bool GestorNutricionalController::eliminarDieta(int id) {
	Dieta^ dieta = consultarDietaporId(id);
	if (dieta != nullptr) {
		this->listaDietas->Remove(dieta);
		return true;
	}
	return false;
}

void GestorNutricionalController::closeDieta() {
	this->listaDietas = nullptr;
}


void GestorNutricionalController::enviarOrdenAlimentacion(int idDieta, String^ prioridad) {
	AlmacenController^ gestorAlmacen = gcnew AlmacenController();

	int nuevoId = gestorAlmacen->listarOrdenes()->Count + 1;
	String^ fecha = DateTime::Now.ToString("yyyy-MM-dd");

	OrdenDistribucion^ nuevaOrden = gcnew OrdenDistribucion(nuevoId, idDieta, "AgroRobot", fecha, "Ruta X", prioridad, nullptr, nullptr, gcnew List<Insumo^>());
	gestorAlmacen->registrarOrden(nuevaOrden);
}

String^ GestorNutricionalController::verificarPesoAnimal(int idAnimal, double pesoEsperado, double peso) {
	Animal^ animal = consultarAnimalporId(idAnimal);
	if (animal == nullptr) {
		return "No se encontró el animal con el ID especificado.";
	}

	// Calculamos diferencia y porcentaje
	double diferencia = peso - pesoEsperado;
	double porcentaje = (diferencia / pesoEsperado) * 100.0;

	String^ mensaje;

	// Determinamos estado según la diferencia
	if (Math::Abs(porcentaje) <= 5) {
		mensaje = "El peso del animal está dentro del rango adecuado.";
		animal->EstadoSalud = "Normal";
	}
	else if (porcentaje > 5) {
		mensaje = String::Format("El animal presenta sobrepeso (+{0:F2}%).", porcentaje);
		animal->EstadoSalud = "Sobrepeso";
	}
	else {
		mensaje = String::Format("El animal presenta bajo peso ({0:F2}%).", porcentaje);
		animal->EstadoSalud = "Bajo peso";
	}

	modificarAnimal(
		idAnimal,
		animal->Especie,
		peso,                      
		animal->Edad,
		animal->EstadoSalud,
		animal->UltimaDieta
	);

	escribirArchivoAnimal();

	return mensaje;
}

List<Animal^>^ GestorNutricionalController::leerArchivoAnimal() {
	listaAnimales->Clear();

	if (!File::Exists("animales.txt")) {
		return listaAnimales;
	}

	array<String^>^ lineas = File::ReadAllLines("animales.txt");
	for each (String ^ linea in lineas) {
		if (String::IsNullOrWhiteSpace(linea)) continue;

		array<String^>^ campos = linea->Split(';');
		// Esperamos: 
		if (campos->Length < 6) continue;

		int idAnimal;
		double peso, edad;

		if (!Int32::TryParse(campos[0], idAnimal)) continue;
		if (!Double::TryParse(campos[2], peso)) peso = 0;
		if (!Double::TryParse(campos[3], edad)) edad = 0;

		// Usamos el constructor intermedio
		Animal^ a = gcnew Animal(
			idAnimal,
			campos[1]->Trim(),   // especie
			peso,
			edad,
			campos[4]->Trim(),   // estadoSalud
			campos[5]->Trim()    // ultimaDieta
		);

		listaAnimales->Add(a);
	}

	return listaAnimales;
}