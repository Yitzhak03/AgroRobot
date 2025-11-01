#pragma once
namespace AgroRobotController {
	using namespace System::Collections::Generic;
	using namespace AgroRobotModel;
	using namespace System;
	public ref class StockInsumoController {
	public:
		StockInsumoController();
		List<StockInsumo^>^ readTxt();
		StockInsumo^ buscarPorId(int id);
		List<StockInsumo^>^ buscarPorIdInsumo(int idInsumo);
		List<StockInsumo^>^ buscarPorIdAlmacen(int idAlmacen);
		int cantidadInsumosEnAlmacen(int idAlmacen);
		
	};
}