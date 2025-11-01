#include "RolController.h"
using namespace AgroRobotController;
using namespace System::IO;

RolController::RolController(){
	this->listaRoles = gcnew List<Rol^>();

	String^ path = "roles.txt";
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
		listaRoles->Add(rol);
	}
}


List<Rol^>^ RolController::readTxt(){
	List<Rol^>^ lista = gcnew List<Rol^>();
	String^ path = "roles.txt";

	if (!File::Exists(path)) {
		File::WriteAllText(path, ""); 
		return lista;
	}

	array<String^>^ lineas = File::ReadAllLines(path);
	for each (String ^ linea in lineas) {
		if (String::IsNullOrWhiteSpace(linea)) continue;

		array<String^>^ datos = linea->Split(';');
		
		int id = Convert::ToInt32(datos[0]);
		String^ nombre = datos[1];

		Rol^ rol = gcnew Rol(id, nombre);

		array<String^>^ permisosTxt = datos[2]->Split('|');
		for each (String ^ permiso in permisosTxt) {
			if (permiso == "1") rol->GetPermisos()->Add(true);
			else rol->GetPermisos()->Add(false);
		}

		lista->Add(rol);
	}
	return lista;
}

void RolController::escribirArchivo(){
	String^ path = "roles.txt";
	// Preparamos el array de líneas con la misma cantidad que la lista
	array<String^>^ lineasArchivo = gcnew array<String^>(this->listaRoles->Count);
	for (int i = 0; i < this->listaRoles->Count; ++i) {
		Rol^ rol = this->listaRoles[i];
		lineasArchivo[i] = rol->GetId() + ";" + rol->GetNombre() + ";";

		// Convertir la lista de permisos a formato "1|0|1"
		List<bool>^ permisos = rol->GetPermisos();
		String^ permisosTxt = "";
		
		for (int j = 0; j < permisos->Count; ++j) {
			permisosTxt += permisos[j] ? "1" : "0";
			if (j < permisos->Count - 1) permisosTxt += "|";
		}

		// Linea completa
		lineasArchivo[i] = rol->GetId() + ";" + rol->GetNombre() + ";" + permisosTxt;
	}
	// Escribimos todas las líneas al archivo (sobrescribe)
	File::WriteAllLines(path, lineasArchivo);
}

void RolController::agregarRol(Rol^ rol) {
	this->listaRoles->Add(rol);
	escribirArchivo();
}

Rol^ RolController::obtenerRolPorId(int id)
{
	List<Rol^>^ lista = readTxt();
	for each (Rol ^ rol in lista) {
		if (rol->Id == id) {
			return rol;
		}
	}
}

Rol^ RolController::obtenerRolPorNombre(String^ nombre) {
	List<Rol^>^ listaRoles = readTxt();
	for each (Rol ^ rol in listaRoles) {
		if (rol->Nombre == nombre) {
			return rol;
		}
	}
}


List<Rol^>^ RolController::obtenerTodosRoles() {
	return this->listaRoles;
}