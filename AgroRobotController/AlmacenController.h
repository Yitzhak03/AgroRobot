#pragma once

namespace AgroRobotController {

	using namespace System::Collections::Generic;
	using namespace AgroRobotModel;

	public ref class AlmacenController {
	private:
		List<OrdenDistribucion^>^ listaOrdenes;

	public:
		AlmacenController();
		List<Almacen^>^ readTxt();
		void writeTxt(List<Almacen^>^ lista);
		void agregarAlmacen(Almacen^ almacen);
		void registrarOrden(OrdenDistribucion^ orden);
		List<OrdenDistribucion^>^ listarOrdenes();
		void cargarOrdenesDesdeArchivo();
		void guardarOrdenesEnArchivo();
		Almacen^ buscarPorId(int id);
		int cantidadInsumosEnAlmacen(int idAlmacen);
	};



}
