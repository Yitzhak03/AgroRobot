#pragma once
#include "BaseController.h"

namespace AgroRobotController {
	using namespace System::Collections::Generic;
	using namespace AgroRobotModel;
	using namespace System;

	public ref class AlmacenController : public BaseController {
	private:
		List<OrdenDistribucion^>^ listaOrdenes;
		String^ archivoOrdenes;

	public:
		AlmacenController();
		// Métodos para base de datos
		List<Almacen^>^ read_BD();
		void agregarAlmacen_BD(Almacen^ almacen);
		Almacen^ buscarPorId_BD(int id);
		String^ buscarNombrePorId_BD(int id);
		int buscarIdPorNombre_BD(String^ nombre);
		List<String^>^ obtenerNombresAlmacenes_BD();
		Almacen^ obtenerAlmacenPorNombre_BD(String^ nombre);
		// Otros métodos
		List<OrdenDistribucion^>^ listarOrdenes();
		void cargarOrdenesDesdeArchivo();
		void guardarOrdenesEnArchivo();
		bool registrarOrden(OrdenDistribucion^ orden);
		void escribirArchivoBINOrdenes();
		int obtenerMaximoIdOrden();
	};
}
