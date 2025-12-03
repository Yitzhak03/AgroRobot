#pragma once

namespace AgroRobotController {
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace AgroRobotModel;

	public ref class RendimientoController {
	private:
		const double segPorAlimentacion = 1.0;
		List<Rendimiento^>^ listaRendimiento;
	
	public:
		RendimientoController();

		List<Rendimiento^>^ buscarTodos();
		void agregarRendimiento(Rendimiento^ rendimiento);
		void actualizarxAnimal(int cantidadAnimales);
		void escribirArchivo();
		
	};
}