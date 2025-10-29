#include "RolController.h"
using namespace AgroRobotController;
using namespace System::IO;
RolController::RolController(){
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

void RolController::writeTxt(List<Rol^>^ lista)
{
	String^ path = "roles.txt";
	// Preparamos el array de líneas con la misma cantidad que la lista
	array<String^>^ lineas = gcnew array<String^>(lista->Count);
	for (int i = 0; i < lista->Count; ++i) {
		Rol^ rol = lista[i];
		lineas[i] = String::Format("{0};{1};{2}",
			rol->Id,
			rol->Nombre,
			rol->Permisos
		);
	}
	// Escribimos todas las líneas al archivo (sobrescribe)
	File::WriteAllLines(path, lineas);
}
int RolController::obtenerIdPorNombre(String^ nombre)
{
	List<Rol^>^ lista = readTxt();
	for each (Rol ^ rol in lista) {
		if (rol->Nombre->Equals(nombre)) {
			return rol->Id;
		}
	}
}