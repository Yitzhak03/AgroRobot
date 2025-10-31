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
		int cantidadInsumosEnAlmacen(int idAlmacen);
		
	};
}