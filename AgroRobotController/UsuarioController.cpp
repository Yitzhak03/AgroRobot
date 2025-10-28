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
		int id = Convert::ToInt32(datos[0]);
		String^ nombre = datos[1];
		String^ email = datos[2];
		String^ contrasenha = datos[3];
		String^ ultimoAcceso = datos[4];
		String^ estadoCuenta = datos[5];

		// Parsear Roles usando '|' como separador
		List<int>^ idsRoles = gcnew List<int>();
		String^ rolesField = datos[6];
		array<String^>^ rolesIds = rolesField->Split('|');
		for each (String ^ rolId in rolesIds)
			idsRoles->Add(Convert::ToInt32(rolId));

		// Parsear Alertas usando '|' como separador
		List<int>^ idsAlertas = gcnew List<int>();
		String^ alertsField = datos[7];
		array<String^>^ alertasIds = alertsField->Split('|');
		if (!String::IsNullOrEmpty(alertsField)) {
			for each (String ^ alertaId in alertasIds)
				idsAlertas->Add(Convert::ToInt32(alertaId));
		}
		else idsAlertas = nullptr;
		
		Usuario^ user = gcnew Usuario(id, nombre, email, contrasenha, ultimoAcceso, estadoCuenta, idsRoles, idsAlertas);
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
		if (u->GetIdsRoles() != nullptr && u->GetIdsRoles()->Count > 0) {
			for (int j = 0; j < u->GetIdsRoles()->Count; ++j) {
				rolesField += u->GetIdsRoles()[j].ToString();
				if (j < u->GetIdsRoles()->Count - 1) // Agregar separador solo si no es el último
					rolesField += "|";
			}
		}
		// Construir campo alerts (separador '|')
		String^ alertsField = "";
		if (u->GetIdsAlertas() != nullptr && u->GetIdsAlertas()->Count > 0) {
			for (int j = 0; j < u->GetIdsAlertas()->Count; ++j) {
				alertsField += u->GetIdsAlertas()[j].ToString();
				if (j < u->GetIdsAlertas()->Count - 1) // Agregar separador solo si no es el último
					alertsField += "|";
			}
		}
		lineas[i] = String::Format("{0};{1};{2};{3};{4};{5};{6};{7}",
			u->GetId(),
			u->GetNombre(),
			u->GetEmail(),
			u->GetContrasenha(),
			u->GetUltimoAcceso(),
			u->GetEstadoCuenta(),
			rolesField,
			alertsField
		);
	}
	// Escribimos todas las líneas al archivo (sobrescribe)
	File::WriteAllLines(path, lineas);
}

void UsuarioController::agregarUsuario(Usuario^ usuario){
	this->listaUsuarios->Add(usuario);
	writeTxt(this->listaUsuarios);
}

List<Usuario^>^ UsuarioController::obtenerTodosUsuarios() {
	return this->listaUsuarios;
}


void UsuarioController::eliminarUsuario(int id)
{
	for each (Usuario ^ usuario in this->listaUsuarios) {
		if (usuario->GetId() == id) {
			this->listaUsuarios->Remove(usuario);
			break;
		}
	}
	writeTxt(this->listaUsuarios);
}

void UsuarioController::actualizarUsuario(Usuario^ usuario)
{
	for (int i = 0; i < this->listaUsuarios->Count; ++i) {
		if (this->listaUsuarios[i]->GetId() == usuario->GetId() ) {
			this->listaUsuarios[i] = usuario;
			break;
		}
	}
	writeTxt(this->listaUsuarios);
}

Usuario^ UsuarioController::obtenerUsuarioPorId(int id){
	for each (Usuario ^ usuario in this->listaUsuarios) {
		if (usuario->GetId() == id) {
			return usuario;
		}
	}
}

List<Usuario^>^ UsuarioController::obtenerUsuarioPorNombreEstado(String^ nombre, String^ estado){
	List<Usuario^>^ resultados = gcnew List<Usuario^>();

	for each (Usuario ^ usuario in this->listaUsuarios) {
		bool coincideNombre = (String::IsNullOrEmpty(nombre) || usuario->GetNombre() == nombre);
		bool coincideEstado = (String::IsNullOrEmpty(estado) || usuario->GetEstadoCuenta() == estado);

		if (coincideNombre && coincideEstado) {
			resultados->Add(usuario);
		}
	}

	return resultados;

}