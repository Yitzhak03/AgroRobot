#include "Usuario.h"

using namespace AgroRobotModel;

Usuario::Usuario(){
	this->Id = 0;
	this->Nombre = "";
	this->Email = "";
	this->Contrasenha = "";
	this->UltimoAcceso = "";
	this->EstadoCuenta = "";
	this->RolUsuario = nullptr;
}

Usuario::Usuario(int id, String^ nombre, String^ email, String^ contrasenha, String^ ultimoAcceso,
					String^ estadoCuenta, Rol^ rol) {
	this->Id = id;
	this->Nombre = nombre;
	this->Email = email;
	this->Contrasenha = contrasenha;
	this->UltimoAcceso = ultimoAcceso;
	this->EstadoCuenta = estadoCuenta;
	this->RolUsuario = rol;
}

int Usuario::GetId() {
	return this->Id;
}
void Usuario::SetId(int id) {
	this->Id = id;
}

String^ Usuario::GetNombre() {
	return this->Nombre;
}
void Usuario::SetNombre(String^ nombre) {
	this->Nombre = nombre;
}

String^ Usuario::GetEmail() {
	return this->Email;
}
void Usuario::SetEmail(String^ email) {
	this->Email = email;
}

String^ Usuario::GetContrasenha() {
	return this->Contrasenha;
}
void Usuario::SetContrasenha(String^ contrasenha) {
	this->Contrasenha = contrasenha;
}

String^ Usuario::GetUltimoAcceso() {
	return this->UltimoAcceso;
}
void Usuario::SetUltimoAcceso(String^ ultimoAcceso) {
	this->UltimoAcceso = ultimoAcceso;
}

String^ Usuario::GetEstadoCuenta() {
	return this->EstadoCuenta;
}
void Usuario::SetEstadoCuenta(String^ estadoCuenta) {
	this->EstadoCuenta = estadoCuenta;
}

Rol^ Usuario::GetRol() {
	return this->RolUsuario;
}
void Usuario::SetRol(Rol^rol) {
	this->RolUsuario = rol;
}