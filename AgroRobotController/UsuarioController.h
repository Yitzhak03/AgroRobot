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
		//List<Usuario^>^ readTxt();
		void writeTxt(List<Usuario^>^ listaUsuarios);
		void agregarUsuario(Usuario^ usuario);
		List<Usuario^>^ obtenerTodosUsuarios();
		void actualizarUsuario(Usuario^ usuario);
		void eliminarUsuario(int id);
		Usuario^ obtenerUsuarioPorId(int id);
		List<Usuario^>^ obtenerUsuarioPorNombreEstado(String^ nombre, String^ estado);
	};
}