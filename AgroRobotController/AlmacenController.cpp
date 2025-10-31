#include "AlmacenController.h"
#include "StockInsumoController.h"
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
	// Id(int);Nombre(String^);Direccion(String^);IdsStockInsumos(int separados por |)
	List<Almacen^>^ lista = gcnew List<Almacen^>();
	String^ path = "almacenes.txt";
	array<String^>^ lineas = File::ReadAllLines(path);
	for each (String ^ linea in lineas) {
		array<String^>^ datos = linea->Split(';');
		Almacen^ almacen = gcnew Almacen();
		almacen->Id = Convert::ToInt32(datos[0]);
		almacen->Nombre = datos[1];
		almacen->Ubicacion = datos[2];
		//Parsear Id de stockInsumo
		array<String^>^ idsStockInsumosStr = datos[3]->Split('|');
		almacen->Stocks = gcnew List<StockInsumo^>();
		StockInsumoController^ stockInsumoController = gcnew StockInsumoController();
		for each (String ^ idStr in idsStockInsumosStr) {
			int idStockInsumo = Convert::ToInt32(idStr);
			StockInsumo^ stockInsumo = stockInsumoController->buscarPorId(idStockInsumo);
			if (stockInsumo != nullptr) {
				almacen->Stocks->Add(stockInsumo);
			}
		}
	}
	return lista;
}
int AlmacenController::cantidadInsumosEnAlmacen(int idAlmacen)
{
	Almacen^ a = buscarPorId(idAlmacen);
	if (a != nullptr) {
		return a->Stocks->Count;
	}
	return 0;
}
void AlmacenController::writeTxt(List<Almacen^>^ lista)
{

}
Almacen^ AlmacenController::buscarPorId(int id)
{
	List<Almacen^>^ lista = readTxt();
	for each (Almacen^ a in lista) {
		if (a->Id == id) {
			return a;
		}
	}
	return nullptr;
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