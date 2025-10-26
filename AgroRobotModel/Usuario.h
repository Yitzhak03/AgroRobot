#pragma once
#include "Rol.h"
#include "Alerta.h"
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
		property List<Rol^>^ Roles;
		property List<Alerta^>^ Alerts;
		Usuario();
		Usuario(
			int id,
			String^ nombre,
			String^ email,
			String^ contrasenha,
			String^ ultimoAcceso,
			String^ estadoCuenta,
			List<Rol^>^ roles,
			List<Alerta^>^ alerts
		);
	};
}