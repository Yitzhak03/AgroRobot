#pragma once
namespace AgroRobotModel {
	using namespace System;
	using namespace System::Collections::Generic;
	public ref class Usuario {
	public:
		property int Id;
		property String^ Nombre;
		property String^ Email;
		property String^ Contrasenha;
		property String^ UltimoAcceso;
		property String^ EstadoCuenta;
		property List<int>^ IdsRoles;
		property List<int>^ IdsAlertas;
		Usuario();
		Usuario(
			int id,
			String^ nombre,
			String^ email,
			String^ contrasenha,
			String^ ultimoAcceso,
			String^ estadoCuenta,
			List<int>^ idsRoles,
			List<int>^ idsAlertas
		);
	};
}