#include "UsuarioController.h"
using namespace AgroRobotController;
using namespace System::IO;
UsuarioController::UsuarioController()
{
}
List<Usuario^>^ UsuarioController::readTxt()
{
	List<Usuario^>^ lista = gcnew List<Usuario^>();
	String^ path = "usuarios.txt";
	array<String^>^ lineas = File::ReadAllLines(path);
	for each (String ^ linea in lineas) {
		if (String::IsNullOrWhiteSpace(linea)) continue;
		array<String^>^ datos = linea->Split(';');
		Usuario^ user = gcnew Usuario();
		user->Id = Convert::ToInt32(datos[0]);
        user->Nombre = datos[1]->Trim();
        user->Email = datos[2]->Trim();
        user->Contrasenha = datos[3]->Trim();
        user->UltimoAcceso = datos[4]->Trim();
        user->EstadoCuenta = datos[5]->Trim();
		// Parsear Roles usando '|' como separador
		user->Roles = gcnew List<Rol^>();
		String^ rolesField = datos[6]->Trim();
		array<String^>^ rolesNames = rolesField->Split('|');
		for each (String^ rn in rolesNames) {
			String^ name = rn->Trim();
			Rol^ r = gcnew Rol();
			r->Nombre = name;
			user->Roles->Add(r);
		}
		// Parsear Alertas usando '|' como separador
		user->Alerts = gcnew List<Alerta^>();
		String^ alertsField = datos[7]->Trim();
		array<String^>^ alertsNames = alertsField->Split('|');
		if (!String::IsNullOrEmpty(alertsField)) {
			for each (String^ alert in alertsNames) {
				String^ type = alert->Trim();
				Alerta^ a = gcnew Alerta();
				a->Tipo = type;
				user->Alerts->Add(a);
			}
		} else user->Alerts = nullptr;
		lista->Add(user);
	}
	return lista;
}
void UsuarioController::writeTxt(List<Usuario^>^ lista)
{
	String^ path = "usuarios.txt";
	// Preparamos el array de líneas con la misma cantidad que la lista
	array<String^>^ lineas = gcnew array<String^>(lista->Count);
	for (int i = 0; i < lista->Count; ++i) {
		Usuario^ usuario = lista[i];
		// Construir campo roles (separador '|')
		String^ rolesField = "";
		if (usuario->Roles != nullptr && usuario->Roles->Count > 0) {
			List<String^>^ roleNames = gcnew List<String^>();
			for each (Rol^ r in usuario->Roles) {
				roleNames->Add((r->Nombre != nullptr) ? r->Nombre->Trim() : "");
			}
			rolesField = String::Join("|", roleNames->ToArray());
		}
		// Construir campo alerts (separador '|')
		String^ alertsField = "";
		if (usuario->Alerts != nullptr && usuario->Alerts->Count > 0) {
			List<String^>^ alertNames = gcnew List<String^>();
			for each (Alerta ^ a in usuario->Alerts) {
				alertNames->Add((a->Tipo != nullptr) ? a->Tipo->Trim() : "");
			}
			alertsField = String::Join("|", alertNames->ToArray());
		}
		lineas[i] = String::Format("{0};{1};{2};{3};{4};{5};{6};{7}",
			usuario->Id,
			(usuario->Nombre != nullptr) ? usuario->Nombre->Trim() : "",
			(usuario->Email != nullptr) ? usuario->Email->Trim() : "",
			(usuario->Contrasenha != nullptr) ? usuario->Contrasenha->Trim() : "",
			(usuario->UltimoAcceso != nullptr) ? usuario->UltimoAcceso->Trim() : "",
			(usuario->EstadoCuenta != nullptr) ? usuario->EstadoCuenta->Trim() : "",
			rolesField,
			alertsField
		);
	}
	// Escribimos todas las líneas al archivo (sobrescribe)
	File::WriteAllLines(path, lineas);
}
void UsuarioController::agregarUsuario(Usuario^ usuario)
{
	List<Usuario^>^ lista = readTxt();
	lista->Add(usuario);
	writeTxt(lista);
}
void UsuarioController::eliminarUsuario(int id)
{
	List<Usuario^>^ lista = readTxt();
	for each (Usuario ^ usuario in lista) {
		if (usuario->Id == id) {
			lista->Remove(usuario);
			break;
		}
	}
	writeTxt(lista);
}
void UsuarioController::actualizarUsuario(Usuario^ usuario)
{
	List<Usuario^>^ lista = readTxt();
	for (int i = 0; i < lista->Count; ++i) {
		if (lista[i]->Id == usuario->Id) {
			lista[i] = usuario;
			break;
		}
	}
	writeTxt(lista);
}
Usuario^ UsuarioController::obtenerUsuarioPorId(int id)
{
	List<Usuario^>^ lista = readTxt();
	for each (Usuario ^ usuario in lista) {
		if (usuario->Id == id) {
			return usuario;
		}
	}
}