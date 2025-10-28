#include "InsumoController.h"
using namespace AgroRobotController;
using namespace System::IO;
using namespace System;
InsumoController::InsumoController()
{
}
List<Insumo^>^ InsumoController::readTxt()
{
	List<Insumo^>^ lista = gcnew List<Insumo^>();
	String^ path = "insumos.txt";
	array<String^>^ lineas = File::ReadAllLines(path);
	for each (String ^ linea in lineas) {
		if (String::IsNullOrWhiteSpace(linea)) continue;
		array<String^>^ datos = linea->Split(';');
		Insumo^ insumo = gcnew Insumo();
		insumo->Id = Convert::ToInt32(datos[0]);
		insumo->Nombre = datos[1];
		insumo->Tipo = datos[2];
		insumo->Stock = Convert::ToSingle(datos[3]);
		insumo->Unidad = datos[4];
		lista->Add(insumo);
	}
	return lista;
}
void InsumoController::writeTxt(List<Insumo^>^ lista)
{
	String^ path = "insumos.txt";
	// Preparamos el array de líneas con la misma cantidad que la lista
	array<String^>^ lineas = gcnew array<String^>(lista->Count);
	for (int i = 0; i < lista->Count; ++i) {
		Insumo^ insumo = lista[i];
		lineas[i] = String::Format("{0};{1};{2};{3};{4}",
			insumo->Id,
			insumo->Nombre,
			insumo->Tipo,
			insumo->Stock,
			insumo->Unidad
		);
	}
	// Escribimos todas las líneas al archivo (sobrescribe)
	File::WriteAllLines(path, lineas);
}
void InsumoController::agregarInsumo(Insumo^ insumo)
{
	List<Insumo^>^ lista = readTxt();
	lista->Add(insumo);
	writeTxt(lista);
}
void InsumoController::eliminarInsumo(int id)
{
	List<Insumo^>^ lista = readTxt();
	for (int i = 0; i < lista->Count; ++i) {
		if (lista[i]->Id == id) {
			lista->RemoveAt(i);
			break;
		}
	}
	writeTxt(lista);
}
void InsumoController::actualizarInsumo(Insumo^ insumo)
{
	List<Insumo^>^ lista = readTxt();
	for (int i = 0; i < lista->Count; ++i) {
		if (lista[i]->Id == insumo->Id) {
			lista[i] = insumo;
			break;
		}
	}
	writeTxt(lista);
}
Insumo^ InsumoController::buscarPorId(int id)
{
	List<Insumo^>^ lista = readTxt();
	for each (Insumo ^ insumo in lista) {
		if (insumo->Id == id) {
			return insumo;
		}
	}
	return nullptr;
}
List<Insumo^>^ InsumoController::buscarPorTipo(String^ tipo)
{
	List<Insumo^>^ lista = readTxt();
	List<Insumo^>^ resultados = gcnew List<Insumo^>();
	for each (Insumo ^ insumo in lista) {
		if (insumo->Tipo->Equals(tipo, StringComparison::OrdinalIgnoreCase)) {
			resultados->Add(insumo);
		}
	}
	return resultados;
}
List<Insumo^>^ InsumoController::buscarPorUnidad(String^ unidad)
{
	List<Insumo^>^ lista = readTxt();
	List<Insumo^>^ resultados = gcnew List<Insumo^>();
	for each (Insumo ^ insumo in lista) {
		if (insumo->Unidad->Equals(unidad, StringComparison::OrdinalIgnoreCase)) {
			resultados->Add(insumo);
		}
	}
	return resultados;
}