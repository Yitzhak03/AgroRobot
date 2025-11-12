#pragma once
namespace AgroRobotController {
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace AgroRobotModel;
	public ref class UsuarioController {
	private:
		List<Usuario^>^ listaUsuarios;
	
	public:
		UsuarioController();
		void escribirArchivo();

		void agregarUsuario(Usuario^ usuario);
		List<Usuario^>^ obtenerUsuariosPorEstado(Nullable<bool> estado);
		List<Usuario^>^ obtenerUsuariosHabilitados();
		List<Usuario^>^ obtenerUsuariosDeshabilitados();
		void actualizarUsuario(Usuario^ usuario);
		void cambiarEstadoUsuario(int id);
		Usuario^ obtenerUsuarioPorId(int id);
		List<Usuario^>^ obtenerUsuarioPorNombreEstado(String^ nombre, Nullable<bool> estado);
	};
}