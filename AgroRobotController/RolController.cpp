#include "RolController.h"
using namespace AgroRobotController;
using namespace System::IO;
RolController::RolController()
{
}
List<Rol^>^ RolController::readTxt()
{
	List<Rol^>^ lista = gcnew List<Rol^>();
	String^ path = "roles.txt";
	array<String^>^ lineas = File::ReadAllLines(path);
	for each (String ^ linea in lineas) {
		if (String::IsNullOrWhiteSpace(linea)) continue;
		array<String^>^ datos = linea->Split(';');
		Rol^ rol = gcnew Rol();
		rol->Id = Convert::ToInt32(datos[0]);
		rol->Nombre = datos[1];
		rol->Permisos = datos[2];
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