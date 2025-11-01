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

		void escribirArchivo();
		
		void agregarRol(Rol^ rol);
		bool eliminarRol(int id);
		bool modificarRol(int id, String^ nombre, List<bool>^ listPermisos);
		Rol^ obtenerRolPorId(int id);
		Rol^ obtenerRolPorNombre(String^ nombre);
		List<Rol^>^ obtenerTodosRoles();
	};
}