#pragma once
namespace AgroRobotController {
	using namespace System::Collections::Generic;
	using namespace AgroRobotModel;
	using namespace System;
	public ref class InsumoController {
	public:
		InsumoController();
		List<Insumo^>^ readTxt();
		void writeTxt(List<Insumo^>^ lista);
		void agregarInsumo(Insumo^ insumo);
		void eliminarInsumo(int id);
		void actualizarInsumo(Insumo^ insumo);
		Insumo^ buscarPorId(int id);
		List<Insumo^>^ buscarPorTipo(String^ tipo);
		List<String^>^ obtenerTiposInsumos();
	};
}