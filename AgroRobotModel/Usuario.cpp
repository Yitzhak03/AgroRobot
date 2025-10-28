#include "Usuario.h"

using namespace AgroRobotModel;

Usuario::Usuario(){
}

Usuario::Usuario(int id, String^ nombre, String^ email, String^ contrasenha, String^ ultimoAcceso,
					String^ estadoCuenta, List<int>^ idsRoles, List<int>^ idsAlertas) {
	this->Id = id;
	this->Nombre = nombre;
	this->Email = email;
	this->Contrasenha = contrasenha;
	this->UltimoAcceso = ultimoAcceso;
	this->EstadoCuenta = estadoCuenta;
	this->IdsRoles = idsRoles;
	this->IdsAlertas = idsAlertas;
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

List<int>^ Usuario::GetIdsRoles() {
	return this->IdsRoles;
}
void Usuario::SetIdsRoles(List<int>^ idsRoles) {
	this->IdsRoles = idsRoles;
}

List<int>^ Usuario::GetIdsAlertas() {
	return this->IdsAlertas;
}
void Usuario::SetIdsAlertas(List<int>^ idsAlertas) {
	this->IdsAlertas = idsAlertas;
}