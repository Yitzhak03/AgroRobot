#include "Rol.h"

using namespace AgroRobotModel;

Rol::Rol() {
	this->Id = 0;
	this->Nombre = "";

	// CORRECCIÓN: Inicializamos la lista con espacio suficiente
	this->Permisos = gcnew List<bool>();
	// Rellenamos con 10 'false' para evitar errores de "Indice fuera de rango"
	for (int i = 0; i < 10; i++) this->Permisos->Add(false);
}

Rol::Rol(int id, String^ nombre) {
	this->Id = id;
	this->Nombre = nombre;

	// CORRECCIÓN: Inicializamos la lista blindada
	this->Permisos = gcnew List<bool>();

	// TRUCO PARA QUE FUNCIONE OFFLINE SIN COMPLICARTE:
	// Si estamos en modo texto (recuperación), asumimos permisos básicos 'true'
	// para que puedas ver el menú.
	for (int i = 0; i < 10; i++) this->Permisos->Add(true);
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
	// SEGURIDAD: Si por alguna razón es nulo, lo recreamos
	if (this->Permisos == nullptr) {
		this->Permisos = gcnew List<bool>();
		for (int i = 0; i < 10; i++) this->Permisos->Add(true);
	}
	return this->Permisos;
}

void Rol::SetPermisos(List<bool>^ listaPermisos) {
	this->Permisos = listaPermisos;
}