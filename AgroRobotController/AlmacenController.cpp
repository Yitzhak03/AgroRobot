#include "AlmacenController.h"
using namespace AgroRobotController;
using namespace System::IO;
using namespace System;
AlmacenController::AlmacenController()
{

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