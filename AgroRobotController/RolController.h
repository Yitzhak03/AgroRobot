#pragma once
#include "BaseController.h"

namespace AgroRobotController {
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace AgroRobotModel;

	public ref class RolController : public BaseController {
	private:
		List<Rol^>^ listaRoles;
		String^ archivo;
	
	public:
		RolController();

		void escribirArchivo();
		
		bool agregarRol(Rol^ rol);
		bool eliminarRol(int id);
		bool modificarRol(int id, String^ nombre, List<bool>^ listPermisos);
		Rol^ obtenerRolPorId(int id);
		Rol^ obtenerRolPorNombre(String^ nombre);
		List<Rol^>^ obtenerTodosRoles();

		void escribirArchivoBINRoles();
		List<bool>^ ConvertirStringAPermisos(String^ permisosString);
		String^ ConvertirPermisosAString(List<bool>^ listaPermisos);
	};
}