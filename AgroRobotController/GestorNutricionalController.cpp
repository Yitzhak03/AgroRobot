#pragma once
#include "GestorNutricionalController.h"

using namespace System::Runtime::Serialization::Formatters::Binary;
using namespace System::IO;
using namespace AgroRobotController;

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
		/*campos obligatorios*/
		int idAnimal = Convert::ToInt32(camposAnimales[0]);
		String^ especie = camposAnimales[1];
		double peso = Convert::ToDouble(camposAnimales[2]);
		double edad = Convert::ToDouble(camposAnimales[3]);
		String^ estadoSalud = camposAnimales[4];
		String^ ultimaDieta = (camposAnimales->Length > 5) ? camposAnimales[5] : "";

		/*para que no haya error*/
		List<Muestra^>^ muestras = gcnew List<Muestra^>();
		Dieta^ dietaa = gcnew Dieta();
		List<HistoriaClinica^>^ historiasClinicas = gcnew List<HistoriaClinica^>();

		Animal^ animal = gcnew Animal(idAnimal, especie, peso, edad, estadoSalud, ultimaDieta, muestras, dietaa, historiasClinicas);
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
								   animal->UltimaDieta;
	}
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
	Dieta^ dieta = consultarDietaporId(dieta->Id);
	if (dieta != nullptr) {
		this->listaDietas->Remove(dieta);
		return true;
	}
	return false;
}

void GestorNutricionalController::closeDieta() {
	this->listaDietas = nullptr;
}


String^ GestorNutricionalController::recibirAlertaConsumo(int idAnimal, double consumo) {
	Animal^ animal = nullptr;
	for each (Animal ^ a in this->listaAnimales) {
		if (a->IdAnimal == idAnimal) {
			animal = a;
			break;
		}
	}
	if (animal == nullptr) {
		return "Animal no encontrado.";
	} 
	if (animal->Dietaa == nullptr) {
		return "El animal no tiene dieta asignada.";
	}

	double consumoEsperado = 100.0;
	double diferencia = consumo - consumoEsperado;

	if (Math::Abs(diferencia) < 10) {
		return "Consumo normal para el animal." + animal->Especie + ".";
	}
	if (diferencia < 0) {
		return "El animal " + animal->Especie + " está consumiendo menos de lo esperado.";
	}
	return "El animal " + animal->Especie + " está consumiendo más de lo esperado.";
}

OrdenDistribucion^ GestorNutricionalController::enviarOrdenAlmacen(int id) {
	Dieta^ dieta = nullptr;
	for each (Dieta ^ d in this->listaDietas) {
		if (d->Id == id) {
			dieta = d;
			break;
		}
	}

	if (dieta == nullptr) {
		return nullptr;
	}

	OrdenDistribucion^ orden = gcnew OrdenDistribucion(
		listaOrdenes->Count + 1,
		id,
		"AgroRobot",
		DateTime::Now.ToString("yyyy-MM-dd HH:mm:ss"),
		"Ruta",
		"Normal",
		nullptr,
		nullptr,
		gcnew List<Insumo^>());

	dieta->OrdenesDistribucion->Add(orden);
	listaOrdenes->Add(orden);

	return orden;
}

bool GestorNutricionalController::guardarHistorialDieta(int idAnimal, Dieta^ nuevaDieta) {
	Animal^ animal = nullptr;
	for each (Animal ^ a in this->listaAnimales) {
		if (a->IdAnimal == idAnimal) {
			animal = a;
			break;
		}
	}

	if (animal == nullptr) {
		return false;
	}

	HistoriaClinica^ nuevaHistoria = gcnew HistoriaClinica();
	nuevaHistoria->IdAnimal = idAnimal;
	nuevaHistoria->RegistrarAnalisis = "";
	nuevaHistoria->RegistrarDietas = "";
	
	if (animal->Dietaa != nullptr) {
		nuevaHistoria->RegistrarDietas = "Cambio de dieta: de [" + animal->Dietaa->Alimentos + "] a [" + nuevaDieta->Alimentos + "]";
	}
	else {
		nuevaHistoria->RegistrarDietas = "Asignación inicial de dieta: [" + nuevaDieta->Alimentos + "]";
	}

	nuevaHistoria->EvolucionSalud = "Pendiente de evaluación";
	nuevaHistoria->PlanesNutricionales = "Dieta actual inciada el " + DateTime::Now.ToString("yyyy-MM-dd");
	nuevaHistoria->ReporteAsociado = nullptr;
	nuevaHistoria->AnalisisRealizados = gcnew List<Analisis^>();

	if (animal->HistoriasClinicas == nullptr) {
		animal->HistoriasClinicas = gcnew List<HistoriaClinica^>();
	}

	animal->HistoriasClinicas->Add(nuevaHistoria);

	animal->Dietaa = nuevaDieta;
	animal->UltimaDieta = DateTime::Now.ToString("yyyy-MM-dd");
	
	return true;
}

List<Animal^>^ GestorNutricionalController::alertaNuevoAnimal() {
	List<Animal^>^ animalesSinDieta = gcnew List <Animal^>();
	for each (Animal ^ animal in this->listaAnimales) {
		if (animal->Dietaa == nullptr) {
			animalesSinDieta->Add(animal);
		}
	}
	return animalesSinDieta;
}