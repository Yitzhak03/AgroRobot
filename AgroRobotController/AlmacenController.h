#pragma once
namespace AgroRobotController {
	using namespace System::Collections::Generic;
	using namespace AgroRobotModel;
	public ref class AlmacenController {
	public:
		AlmacenController();
		List<Almacen^>^ readTxt();
		void writeTxt(List<Almacen^>^ lista);
		void agregarAlmacen(Almacen^ almacen);

	
	
	};



}
