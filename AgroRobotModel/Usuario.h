#pragma once
#include "Rol.h"

namespace AgroRobotModel {
	using namespace System;
	using namespace System::Collections::Generic;

	public ref class Usuario {
	protected:
		property int Id;
		property String^ Nombre;
		property String^ Email;
		property String^ Contrasenha;
		property String^ UltimoAcceso;
		property String^ EstadoCuenta;
		property Rol^ RolUsuario;
	
	public:
		
		Usuario();
		Usuario(int id, String^ nombre, String^ email, String^ contrasenha, String^ ultimoAcceso, 
			String^ estadoCuenta,Rol^ rol);

		int GetId();
		void SetId(int id);

		String^ GetNombre();
		void SetNombre(String^ nombre);

		String^ GetEmail();
		void SetEmail(String^ email);

		String^ GetContrasenha();
		void SetContrasenha(String^ contrasenha);

		String^ GetUltimoAcceso();
		void SetUltimoAcceso(String^ ultimoAcceso);

		String^ GetEstadoCuenta();
		void SetEstadoCuenta(String^ estadoCuenta);

		Rol^ GetRol();
		void SetRol(Rol^ rol);
	};
}