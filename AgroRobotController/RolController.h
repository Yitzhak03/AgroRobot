#pragma once
namespace AgroRobotController {
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace AgroRobotModel;
	public ref class RolController {
	public:
		RolController();
		List<Rol^>^ readTxt();
		void writeTxt(List<Rol^>^ lista);
	};
}