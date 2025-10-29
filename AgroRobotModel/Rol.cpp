#include "Rol.h"

using namespace AgroRobotModel;


Rol::Rol() {

}

Rol::Rol(int id, String^ nombre) {
	this->Id = id;
	this->Nombre = nombre;
	this->Permisos = gcnew List<bool>();
}

int Rol::GetId() {
    return this->Id;
}

void Rol::SetId(int id) {
    this->Id = id;
}

String^ Rol::GetNombre() {
    return this->Nombre;
}

void Rol::SetNombre(String^ nombre) {
    this->Nombre = nombre;
}

List<bool>^ Rol::GetPermisos() {
    return this->Permisos;
}

void Rol::SetPermisos(List<bool>^ listaPermisos) {
    this->Permisos = listaPermisos;
}


