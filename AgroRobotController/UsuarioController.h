#pragma once
namespace AgroRobotController {
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace AgroRobotModel;
	public ref class UsuarioController {
	private:
		List<Usuario^>^ listaUsuarios;
		List<Usuario^>^ listaDeshabilitados;
	
	public:
		UsuarioController();
		void escribirArchivo(bool habilitado);

		void agregarUsuario(Usuario^ usuario);
		List<Usuario^>^ obtenerTodosUsuarios(bool habilitado);
		void actualizarUsuario(Usuario^ usuario);
		void cambiarEstadoUsuario(int id);
		Usuario^ obtenerUsuarioPorId(int id);
		List<Usuario^>^ obtenerUsuarioPorNombreEstado(String^ nombre, String^ estado);
	};
}