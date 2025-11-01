#include "RolController.h"
using namespace AgroRobotController;
using namespace System::IO;

RolController::RolController(){
	this->listaRoles = gcnew List<Rol^>();

	String^ path = "roles.txt";
	
	if (!File::Exists(path)) {
		File::WriteAllText(path, "");
	}
	
	array<String^>^ lineas = File::ReadAllLines(path);

	for each (String ^ linea in lineas) {
		if (String::IsNullOrWhiteSpace(linea)) continue;
		array<String^>^ datos = linea->Split(';');
		int id = Convert::ToInt32(datos[0]);
		String^ nombre = datos[1];


		// Parsear Permisos usando '|' como separador
		List<bool>^ listaPermisos = gcnew List<bool>();

		String^ permisosTxt = datos[2];
		array<String^>^ permisosBoolean = permisosTxt->Split('|');
		if (!String::IsNullOrEmpty(permisosTxt)) {
			for each (String ^ permisoBool in permisosBoolean)
				listaPermisos->Add(Convert::ToBoolean(Convert::ToInt32(permisoBool)));
		}
		else listaPermisos = nullptr;

		Rol^ rol = gcnew Rol(id, nombre);
		rol->SetPermisos(listaPermisos);
		listaRoles->Add(rol);
	}
}

void RolController::escribirArchivo(){
	String^ path = "roles.txt";
	// Preparamos el array de líneas con la misma cantidad que la lista
	array<String^>^ lineasArchivo = gcnew array<String^>(this->listaRoles->Count);
	for (int i = 0; i < this->listaRoles->Count; ++i) {
		Rol^ rol = this->listaRoles[i];
		lineasArchivo[i] = rol->GetId() + ";" + rol->GetNombre() + ";";

		// Convertir la lista de permisos a formato "1|0|1|0"
		List<bool>^ permisos = rol->GetPermisos();
		String^ permisosTxt = "";
		
		for (int j = 0; j < permisos->Count; ++j) {
			if (permisos[j]) {
				permisosTxt += "1";
			}
			else {
				permisosTxt += "0";
			}
			
			if (j < permisos->Count - 1) permisosTxt += "|";
		}

		// Linea completa
		lineasArchivo[i] = rol->GetId() + ";" + rol->GetNombre() + ";" + permisosTxt;
	}
	// Escribimos todas las líneas al archivo 
	File::WriteAllLines(path, lineasArchivo);
}

void RolController::agregarRol(Rol^ rol) {
	this->listaRoles->Add(rol);
	escribirArchivo();
}

bool RolController::eliminarRol(int id) {
	Rol^ rol = obtenerRolPorId(id);
	if (rol != nullptr) {
		this->listaRoles->Remove(rol);
		escribirArchivo();
		return true;
	}
	return false;
}

bool RolController::modificarRol(int id, String^ nombre, List<bool>^ listaPermisos) {
	Rol^ rol = obtenerRolPorId(id);

	if (rol != nullptr) {
		rol->SetNombre(nombre);
		rol->SetPermisos(listaPermisos);
		escribirArchivo();
		return true;
	}
	return false;
}

Rol^ RolController::obtenerRolPorId(int id){
	for each (Rol ^ rol in this->listaRoles) {
		if (rol->Id == id) {
			return rol;
		}
	}
}

Rol^ RolController::obtenerRolPorNombre(String^ nombre) {
	for each (Rol ^ rol in this->listaRoles) {
		if (rol->Nombre == nombre) {
			return rol;
		}
	}
}


List<Rol^>^ RolController::obtenerTodosRoles() {
	return this->listaRoles;
}