#pragma once
#include "BaseController.h"
namespace AgroRobotController {
	using namespace System::Collections::Generic;
	using namespace AgroRobotModel;
	using namespace System;
	public ref class InsumoController : public BaseController {
	public:
		InsumoController();
		// Métodos para base de datos
		List<Insumo^>^ read_BD();
		void agregarInsumo_BD(Insumo^ insumo);
		void eliminarInsumo_BD(int id);
		void actualizarInsumo_BD(Insumo^ insumo);
		Insumo^ buscarPorId_BD(int id);
		List<Insumo^>^ buscarPorTipo_BD(String^ tipo);
		List<String^>^ obtenerTiposInsumos_BD();
	};
}