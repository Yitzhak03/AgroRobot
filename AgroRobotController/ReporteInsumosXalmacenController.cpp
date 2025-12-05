#include "ReporteInsumosXalmacenController.h"
#include "AlmacenController.h"
#include "StockInsumoController.h"
using namespace AgroRobotController;

ReporteInsumosXalmacenController::ReporteInsumosXalmacenController()
{

}
List<ReporteInsumosXalmacen^>^ ReporteInsumosXalmacenController::generarReporte()
{
	// Crear una lista para almacenar el reporte
	List<ReporteInsumosXalmacen^>^ reporte = gcnew List<ReporteInsumosXalmacen^>();
	// Obtener la lista de almacenes
	AlmacenController^ almCtrl = gcnew AlmacenController();
	List<Almacen^>^ almacenes = almCtrl->readTxt();
	// Contar los insumos por cada almacen
	StockInsumoController^ stockCtrl = gcnew StockInsumoController();
	for each (Almacen^ a in almacenes) {
		int cantInsumos = stockCtrl->cantidadInsumosEnAlmacen_BD(a->Id);
		ReporteInsumosXalmacen^ reporteItem = gcnew ReporteInsumosXalmacen(a->Nombre, cantInsumos);
		reporte->Add(reporteItem);
	}
	return reporte;
}
