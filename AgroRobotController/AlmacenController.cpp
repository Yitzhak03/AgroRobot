#include "AlmacenController.h"
using namespace AgroRobotController;
using namespace System::IO;
using namespace System;

AlmacenController::AlmacenController()
{
	this->listaOrdenes = gcnew List<OrdenDistribucion^>();

	if (!File::Exists("ordenes.txt")) {
		File::WriteAllText("ordenes.txt", "");
	}
	this->cargarOrdenesDesdeArchivo();
}

List<Almacen^>^ AlmacenController::readTxt()
{
	// Leer txt de la forma:
	// Id(int);Nombre(String^);Ubicacion(String^)
	List<Almacen^>^ lista = gcnew List<Almacen^>();
	String^ path = "almacenes.txt";
	array<String^>^ lineas = File::ReadAllLines(path);
	for each (String ^ linea in lineas) {
		array<String^>^ datos = linea->Split(';');
		Almacen^ almacen = gcnew Almacen();
		almacen->Id = Convert::ToInt32(datos[0]);
		almacen->Nombre = datos[1];
		almacen->Ubicacion = datos[2];
		lista->Add(almacen);
	}
	return lista;
}

void AlmacenController::writeTxt(List<Almacen^>^ lista)
{
	String^ path = "almacenes.txt";
	List<String^>^ lineas = gcnew List<String^>();
	for each (Almacen ^ a in lista) {
		String^ linea = Convert::ToString(a->Id) + ";" + a->Nombre + ";" + a->Ubicacion;
		lineas->Add(linea);
	}
	File::WriteAllLines(path, lineas->ToArray());
}

Almacen^ AlmacenController::buscarPorId(int id)
{
	List<Almacen^>^ lista = readTxt();
	for each (Almacen ^ a in lista) {
		if (a->Id == id) {
			return a;
		}
	}
	return nullptr;
}

void AlmacenController::agregarAlmacen(Almacen^ almacen)
{
	List<Almacen^>^ lista = readTxt();
	lista->Add(almacen);
	// Escribir de nuevo el archivo
	writeTxt(lista);
}

int AlmacenController::generarNuevoId()
{
	List<Almacen^>^ lista = readTxt();
	int maxId = -1;
	for each (Almacen ^ a in lista) {
		if (a->Id > maxId) {
			maxId = a->Id;
		}
	}
	return maxId + 1;
}
List<String^>^ AlmacenController::obtenerNombresAlmacenes()
{
	List<Almacen^>^ lista = readTxt();
	List<String^>^ nombres = gcnew List<String^>();
	for each (Almacen ^ a in lista) {
		nombres->Add(a->Nombre);
	}
	return nombres;
}
Almacen^ AlmacenController::obtenerAlmacenPorNombre(String^ nombre)
{
	List<Almacen^>^ lista = readTxt();
	for each (Almacen ^ a in lista) {
		if (a->Nombre == nombre) {
			return a;
		}
	}
	return nullptr;
}
String^ AlmacenController::buscarNombrePorId(int id)
{
	List<Almacen^>^ lista = readTxt();
	for each (Almacen ^ a in lista) {
		if (a->Id == id) {
			return a->Nombre;
		}
	}
	return "";
}
int AlmacenController::buscarIdPorNombre(String^ nombre)
{
	List<Almacen^>^ lista = readTxt();
	for each (Almacen ^ a in lista) {
		if (a->Nombre == nombre) {
			return a->Id;
		}
	}
	return -1;
}
//=====================================OTROS=================================================
void AlmacenController::guardarOrdenesEnArchivo()
{
	List<String^>^ lineas = gcnew List<String^>();
	for each (OrdenDistribucion ^ orden in this->listaOrdenes) {
		String^ linea = orden->Id + ";" +
			orden->IdDieta + ";" +
			orden->RobotAsignado + ";" +
			orden->FechaHoraEntrega + ";" +
			orden->Ruta + ";" +
			orden->Prioridad;
		lineas->Add(linea);
	}
	File::WriteAllLines("ordenes.txt", lineas->ToArray());
}
void AlmacenController::cargarOrdenesDesdeArchivo()
{
	array<String^>^ lineas = File::ReadAllLines("ordenes.txt");
	String^ separador = ";";
	for each (String ^ linea in lineas) {
		if (String::IsNullOrWhiteSpace(linea)) continue;

		array<String^>^ datos = linea->Split(separador->ToCharArray());
		if (datos->Length < 6) continue;

		int id = Convert::ToInt32(datos[0]);
		int idDieta = Convert::ToInt32(datos[1]);
		String^ robot = datos[2];
		String^ fecha = datos[3];
		String^ ruta = datos[4];
		String^ prioridad = datos[5];

		OrdenDistribucion^ orden = gcnew OrdenDistribucion(id, idDieta, robot, fecha, ruta, prioridad, nullptr, nullptr, gcnew List<Insumo^>());
		this->listaOrdenes->Add(orden);
	}
}
void AlmacenController::registrarOrden(OrdenDistribucion^ orden)
{
	this->listaOrdenes->Add(orden);
	this->guardarOrdenesEnArchivo();
}
List <OrdenDistribucion^>^ AlmacenController::listarOrdenes()
{
	return this->listaOrdenes;
}