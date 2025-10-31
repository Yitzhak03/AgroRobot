#pragma once
namespace AgroRobotController {
	using namespace System::Collections::Generic;
	using namespace AgroRobotModel;
	using namespace System;
	public ref class StockInsumoController {
	public:
		StockInsumoController();
		List<StockInsumo^>^ readTxt();
		/*void writeTxt(List<Insumo^>^ lista);
		void agregarInsumo(Insumo^ insumo);
		void eliminarInsumo(int id);
		void actualizarInsumo(Insumo^ insumo);*/
		StockInsumo^ buscarPorId(int id);
		int cantidadInsumosEnAlmacen(int idAlmacen);
		/*List<Insumo^>^ buscarPorTipo(String^ tipo);
		List<String^>^ obtenerTiposInsumos();
		int generarNuevoId();*/
	};
}