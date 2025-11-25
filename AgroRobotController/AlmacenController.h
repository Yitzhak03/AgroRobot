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
		List<Almacen^>^ readTxt();
		void writeTxt(List<Almacen^>^ lista);
		void agregarAlmacen(Almacen^ almacen);
		bool registrarOrden(OrdenDistribucion^ orden);
		List<OrdenDistribucion^>^ listarOrdenes();
		void cargarOrdenesDesdeArchivo();
		void guardarOrdenesEnArchivo();
		Almacen^ buscarPorId(int id);
		String^ buscarNombrePorId(int id);
		int buscarIdPorNombre(String^ nombre);
		int generarNuevoId();
		List<String^>^ obtenerNombresAlmacenes();
		Almacen^ obtenerAlmacenPorNombre(String^ nombre);

		void escribirArchivoBINOrdenes();
		int obtenerMaximoIdOrden();
	};
}
