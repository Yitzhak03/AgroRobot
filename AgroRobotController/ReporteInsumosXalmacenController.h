#pragma once
namespace AgroRobotController {
	using namespace System::Collections::Generic;
	using namespace AgroRobotModel;
	//using namespace System;
	public ref class ReporteInsumosXalmacenController {
	public:
		ReporteInsumosXalmacenController();
		List<ReporteInsumosXalmacen^>^ generarReporte();
	};
}