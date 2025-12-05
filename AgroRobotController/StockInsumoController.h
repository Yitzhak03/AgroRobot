#pragma once
#include "BaseController.h"
namespace AgroRobotController {
	using namespace System::Collections::Generic;
	using namespace AgroRobotModel;
	using namespace System;
	public ref class StockInsumoController : public BaseController {
	public:
		StockInsumoController();
		//List<StockInsumo^>^ readTxt();
		//void writeTxt(List<StockInsumo^>^ lista);
		//void agregarStockInsumo(StockInsumo^ stockInsumo);
		//int generarNuevoId();
		//void actualizarStockInsumo(StockInsumo^ stockInsumo);
		//StockInsumo^ buscarPorId(int id);
		//List<StockInsumo^>^ buscarPorIdInsumo(int idInsumo);
		//List<StockInsumo^>^ buscarPorIdAlmacen(int idAlmacen);
		//StockInsumo^ buscarPorIdInsumoYAlmacen(int idInsumo, int idAlmacen);
		//int cantidadInsumosEnAlmacen(int idAlmacen);
		////void transferirInsumo(int idInsumo, int idAlmacenOrigen, int idAlmacenDestino, float cantidad);

		// Metodo para base de datos
		List<StockInsumo^>^ read_BD();
		void agregarStockInsumo_BD(StockInsumo^ stockInsumo);
		void actualizarStockInsumo_BD(StockInsumo^ stockInsumo);
		StockInsumo^ buscarPorId_BD(int id);
		List<StockInsumo^>^ buscarPorIdInsumo_BD(int idInsumo);
		List<StockInsumo^>^ buscarPorIdAlmacen_BD(int idAlmacen);
		StockInsumo^ buscarPorIdInsumoYAlmacen_BD(int idInsumo, int idAlmacen);
		int cantidadInsumosEnAlmacen_BD(int idAlmacen);


	};
}