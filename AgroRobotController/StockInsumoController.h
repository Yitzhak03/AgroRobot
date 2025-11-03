#pragma once
namespace AgroRobotController {
	using namespace System::Collections::Generic;
	using namespace AgroRobotModel;
	using namespace System;
	public ref class StockInsumoController {
	public:
		StockInsumoController();
		List<StockInsumo^>^ readTxt();
		void writeTxt(List<StockInsumo^>^ lista);
		void agregarStockInsumo(StockInsumo^ stockInsumo);
		int generarNuevoId();
		void actualizarStockInsumo(StockInsumo^ stockInsumo);
		StockInsumo^ buscarPorId(int id);
		List<StockInsumo^>^ buscarPorIdInsumo(int idInsumo);
		List<StockInsumo^>^ buscarPorIdAlmacen(int idAlmacen);
		StockInsumo^ buscarPorIdInsumoYAlmacen(int idInsumo, int idAlmacen);
		int cantidadInsumosEnAlmacen(int idAlmacen);
		//void transferirInsumo(int idInsumo, int idAlmacenOrigen, int idAlmacenDestino, float cantidad);


	};
}