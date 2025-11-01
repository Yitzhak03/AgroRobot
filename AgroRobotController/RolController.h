#pragma once
namespace AgroRobotController {
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace AgroRobotModel;
	public ref class RolController {
	private:
		List<Rol^>^ listaRoles;
	
	public:
		RolController();

		List<Rol^>^ readTxt();
		void escribirArchivo();
		
		void agregarRol(Rol^ rol);
		Rol^ obtenerRolPorId(int id);
		Rol^ obtenerRolPorNombre(String^ nombre);
		List<Rol^>^ obtenerTodosRoles();
	};
}