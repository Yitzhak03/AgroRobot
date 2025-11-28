#pragma once
#include "BaseController.h"
namespace AgroRobotController {
	using namespace System::Collections::Generic;
	using namespace AgroRobotModel;
	using namespace System;
	public ref class InsumoController : public BaseController {
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
		int generarNuevoId();

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