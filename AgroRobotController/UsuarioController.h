#pragma once
namespace AgroRobotController {
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace AgroRobotModel;
	public ref class UsuarioController {
	public:
		UsuarioController();
		List<Usuario^>^ readTxt();
		void writeTxt(List<Usuario^>^ lista);
		void agregarUsuario(Usuario^ usuario);
		void actualizarUsuario(Usuario^ usuario);
		void eliminarUsuario(int id);
		Usuario^ obtenerUsuarioPorId(int id);
	};
}