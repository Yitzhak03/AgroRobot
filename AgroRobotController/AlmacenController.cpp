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
	List<Almacen^>^ lista = gcnew List<Almacen^>();
	//String^ path = "almacenes.txt";
	//array<String^>^ lineas = File::ReadAllLines(path);
	//for each (String ^ linea in lineas) {
	//	if (String::IsNullOrWhiteSpace(linea)) continue;
	//	array<String^>^ datos = linea->Split(';');
	//	Almacen^ almacen = gcnew Almacen();
	//	almacen->Id = Convert::ToInt32(datos[0]);
	//	almacen->Ubicacion = datos[1];
	//	almacen->Capacidad = Convert::ToSingle(datos[2]);
	//	//Parsear Id de insumos (separados por |)
	//	List<Insumo^>^ insumos = gcnew List<Insumo^>();
	//	array<String^>^ idsInsumos = datos[3]->Split('|');
	//	for each (String ^ idInsumo in idsInsumos) {
	//		if (String::IsNullOrWhiteSpace(idInsumo)) continue;



	//		Insumo^ insumo = gcnew Insumo();
	//		insumo->Codigo = codigo;
	//		insumos->Add(insumo);
	//	}



	//	lista->Add(almacen);
	//}
	return lista;
}
void AlmacenController::writeTxt(List<Almacen^>^ lista)
{

}
void AlmacenController::agregarAlmacen(Almacen^ almacen)
{

}

//======================================================================//
void AlmacenController::registrarOrden(OrdenDistribucion^ orden)
{
	this->listaOrdenes->Add(orden);
	this->guardarOrdenesEnArchivo();
}

List <OrdenDistribucion^>^ AlmacenController::listarOrdenes()
{
	return this->listaOrdenes;
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