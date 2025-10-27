#include "UsuarioController.h"

using namespace AgroRobotController;
using namespace System::IO;

UsuarioController::UsuarioController(){
	this->listaUsuarios = gcnew List<Usuario^>();
	
	String^ path = "usuarios.txt";
	array<String^>^ lineas = File::ReadAllLines(path);

	for each (String ^ linea in lineas) {
		if (String::IsNullOrWhiteSpace(linea)) continue;
		array<String^>^ datos = linea->Split(';');
		Usuario^ user = gcnew Usuario();
		user->Id = Convert::ToInt32(datos[0]);
		user->Nombre = datos[1];
		user->Email = datos[2];
		user->Contrasenha = datos[3];
		user->UltimoAcceso = datos[4];
		user->EstadoCuenta = datos[5];

		// Parsear Roles usando '|' como separador
		user->IdsRoles = gcnew List<int>();
		String^ rolesField = datos[6];
		array<String^>^ rolesIds = rolesField->Split('|');
		for each (String ^ rolId in rolesIds)
			user->IdsRoles->Add(Convert::ToInt32(rolId));

		// Parsear Alertas usando '|' como separador
		user->IdsAlertas = gcnew List<int>();
		String^ alertsField = datos[7];
		array<String^>^ alertasIds = alertsField->Split('|');
		if (!String::IsNullOrEmpty(alertsField)) {
			for each (String ^ alertaId in alertasIds)
				user->IdsAlertas->Add(Convert::ToInt32(alertaId));
		}
		else user->IdsAlertas = nullptr;
		listaUsuarios->Add(user);
	}

}

//List<Usuario^>^ UsuarioController::readTxt(){
//	List<Usuario^>^ lista = gcnew List<Usuario^>();
//	String^ path = "usuarios.txt";
//	array<String^>^ lineas = File::ReadAllLines(path);

//	for each (String ^ linea in lineas) {
//		if (String::IsNullOrWhiteSpace(linea)) continue;
//		array<String^>^ datos = linea->Split(';');
//		Usuario^ user = gcnew Usuario();
//		user->Id = Convert::ToInt32(datos[0]);
//		user->Nombre = datos[1];
//		user->Email = datos[2];
//		user->Contrasenha = datos[3];
//		user->UltimoAcceso = datos[4];
//		user->EstadoCuenta = datos[5];

		// Parsear Roles usando '|' como separador
//		user->IdsRoles = gcnew List<int>();
//		String^ rolesField = datos[6];
//		array<String^>^ rolesIds = rolesField->Split('|');
//		for each (String ^ rolId in rolesIds)
//			user->IdsRoles->Add(Convert::ToInt32(rolId));

		// Parsear Alertas usando '|' como separador
//		user->IdsAlertas = gcnew List<int>();
//		String^ alertsField = datos[7];
//		array<String^>^ alertasIds = alertsField->Split('|');
//		if (!String::IsNullOrEmpty(alertsField)) {
//			for each (String ^ alertaId in alertasIds)
//				user->IdsAlertas->Add(Convert::ToInt32(alertaId));
//		} else user->IdsAlertas = nullptr;
//		lista->Add(user);
//	}
//	return lista;
//}

void UsuarioController::writeTxt(List<Usuario^>^ lista)
{
	String^ path = "usuarios.txt";
	// Preparamos el array de líneas con la misma cantidad que la lista
	array<String^>^ lineas = gcnew array<String^>(lista->Count);
	for (int i = 0; i < lista->Count; ++i) {
		Usuario^ u = lista[i];
		// Construir campo roles (separador '|')
		String^ rolesField = "";
		if (u->IdsRoles != nullptr && u->IdsRoles->Count > 0) {
			for (int j = 0; j < u->IdsRoles->Count; ++j) {
				rolesField += u->IdsRoles[j].ToString();
				if (j < u->IdsRoles->Count - 1) // Agregar separador solo si no es el último
					rolesField += "|";
			}
		}
		// Construir campo alerts (separador '|')
		String^ alertsField = "";
		if (u->IdsAlertas != nullptr && u->IdsAlertas->Count > 0) {
			for (int j = 0; j < u->IdsAlertas->Count; ++j) {
				alertsField += u->IdsAlertas[j].ToString();
				if (j < u->IdsAlertas->Count - 1) // Agregar separador solo si no es el último
					alertsField += "|";
			}
		}
		lineas[i] = String::Format("{0};{1};{2};{3};{4};{5};{6};{7}",
			u->Id,
			u->Nombre,
			u->Email,
			u->Contrasenha,
			u->UltimoAcceso,
			u->EstadoCuenta,
			rolesField,
			alertsField
		);
	}
	// Escribimos todas las líneas al archivo (sobrescribe)
	File::WriteAllLines(path, lineas);
}

void UsuarioController::agregarUsuario(Usuario^ usuario)
{
	this->listaUsuarios->Add(usuario);
	writeTxt(this->listaUsuarios);
}

List<Usuario^>^ UsuarioController::obtenerTodosUsuarios() {
	return this->listaUsuarios;
}


void UsuarioController::eliminarUsuario(int id)
{
	for each (Usuario ^ usuario in this->listaUsuarios) {
		if (usuario->Id == id) {
			this->listaUsuarios->Remove(usuario);
			break;
		}
	}
	writeTxt(this->listaUsuarios);
}

void UsuarioController::actualizarUsuario(Usuario^ usuario)
{
	for (int i = 0; i < this->listaUsuarios->Count; ++i) {
		if (this->listaUsuarios[i]->Id == usuario->Id) {
			this->listaUsuarios[i] = usuario;
			break;
		}
	}
	writeTxt(this->listaUsuarios);
}

Usuario^ UsuarioController::obtenerUsuarioPorId(int id){
	for each (Usuario ^ usuario in this->listaUsuarios) {
		if (usuario->Id == id) {
			return usuario;
		}
	}
}

List<Usuario^>^ UsuarioController::obtenerUsuarioPorNombreEstado(String^ nombre, String^ estado){
	List<Usuario^>^ resultados = gcnew List<Usuario^>();

	for each (Usuario ^ usuario in this->listaUsuarios) {
		bool coincideNombre = (String::IsNullOrEmpty(nombre) || usuario->EstadoCuenta == nombre);
		bool coincideEstado = (String::IsNullOrEmpty(estado) || usuario->EstadoCuenta == estado);

		if (coincideNombre && coincideEstado) {
			resultados->Add(usuario);
		}
	}

	return resultados;

}