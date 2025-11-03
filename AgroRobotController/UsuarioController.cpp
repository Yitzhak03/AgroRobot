#include "UsuarioController.h"
#include "RolController.h"

using namespace AgroRobotController;
using namespace System::IO;

UsuarioController::UsuarioController(){
	this->listaUsuarios = gcnew List<Usuario^>();
	this->listaDeshabilitados = gcnew List<Usuario^>();
	
	String^ path = "usuarios.txt";
	String^ path_2 = "deshabilitados.txt";

	/*crea el txt de habilitados y deshabilitados*/
	if (!File::Exists(path)) {
		File::WriteAllText(path, "");
	}

	if (!File::Exists(path_2)) {
		File::WriteAllText(path_2, "");
	}

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
		
		int idRol = Convert::ToInt32(datos[6]);
		RolController^ rolController = gcnew RolController();
		Rol^ rol = rolController->obtenerRolPorId(idRol);
		
		Usuario^ user = gcnew Usuario(id, nombre, email, contrasenha, ultimoAcceso, estadoCuenta, rol);
		listaUsuarios->Add(user);
	}

	/*lectura para usuarios deshabilitados*/
	array<String^>^ lineas_2 = File::ReadAllLines(path_2);

	for each (String ^ line in lineas_2) {
		if (String::IsNullOrWhiteSpace(line)) continue;
		array<String^>^ datos = line->Split(';');
		int id = Convert::ToInt32(datos[0]);
		String^ nombre = datos[1];
		String^ email = datos[2];
		String^ contrasenha = datos[3];
		String^ ultimoAcceso = datos[4];
		String^ estadoCuenta = datos[5];

		int idRol = Convert::ToInt32(datos[6]);
		RolController^ rolController = gcnew RolController();
		Rol^ rol = rolController->obtenerRolPorId(idRol);

		Usuario^ user = gcnew Usuario(id, nombre, email, contrasenha, ultimoAcceso, estadoCuenta, rol);
		listaDeshabilitados->Add(user);
	}

}

void UsuarioController::escribirArchivo(bool habilitado){
	String^ path;

	if (habilitado) {
		path = "usuarios.txt";
	}
	else {
		path = "deshabilitados.txt";
	}

	// Preparamos el array de líneas con la misma cantidad que la lista
	List<Usuario^>^ lista = gcnew List<Usuario^>();

	/*se decide si los cambios se harán en la lista de usuarios habilitados o la de deshabilitados*/
	lista = (habilitado) ? this->listaUsuarios : this->listaDeshabilitados;

	array<String^>^ lineasArchivo = gcnew array<String^>(lista->Count);

	for (int i = 0; i < lista->Count; ++i) {
		Usuario^ usuario = lista[i];
		lineasArchivo[i] = usuario->GetId() + ";" + usuario->GetNombre() + ";" + usuario->GetEmail() + ";" +
			usuario->GetContrasenha() + ";" + usuario->GetUltimoAcceso() + ";" + usuario->GetEstadoCuenta() + ";" +
			 usuario->GetRol()->GetId();
	}
	// Escribimos todas las líneas al archivo (sobrescribe)
	File::WriteAllLines(path, lineasArchivo);
}

void UsuarioController::agregarUsuario(Usuario^ usuario){
	this->listaUsuarios->Add(usuario);
	escribirArchivo(true);
}

List<Usuario^>^ UsuarioController::obtenerTodosUsuarios(bool habilitado) {
	if (habilitado) {
		return this->listaUsuarios;
	}
	else {
		return this->listaDeshabilitados;
	}
}


void UsuarioController::cambiarEstadoUsuario(int id)
{
	for each (Usuario ^ usuario in this->listaUsuarios) {
		if (usuario->GetId() == id) {
			this->listaDeshabilitados->Add(usuario);
			this->listaUsuarios->Remove(usuario);
			usuario->SetEstadoCuenta("Deshabilitado");
			break;
		}
	}
	escribirArchivo(true);
	escribirArchivo(false);
}

void UsuarioController::actualizarUsuario(Usuario^ usuario)
{
	for (int i = 0; i < this->listaUsuarios->Count; ++i) {
		if (this->listaUsuarios[i]->GetId() == usuario->GetId() ) {
			this->listaUsuarios[i] = usuario;
			break;
		}
	}
	escribirArchivo(true);
}

Usuario^ UsuarioController::obtenerUsuarioPorId(int id){
	List<Usuario^>^ lista = this->listaUsuarios;
	lista->AddRange(this->listaDeshabilitados);
	for each (Usuario ^ usuario in this->listaUsuarios) {
		if (usuario->GetId() == id) {
			return usuario;
		}
	}
}

List<Usuario^>^ UsuarioController::obtenerUsuarioPorNombreEstado(String^ nombre, String^ estado){
	List<Usuario^>^ resultados = gcnew List<Usuario^>();
	List<Usuario^>^ listaBusqueda = gcnew List<Usuario^>();

	/*si no se escoge estado se busca en ambos, si se escoge se busca solo en una de ellas*/
	if (estado == "") {
		listaBusqueda->AddRange(this->listaUsuarios);
		listaBusqueda->AddRange(this->listaDeshabilitados);
	}
	else {
		listaBusqueda = (estado == "Habilitado") ? this->listaUsuarios : this->listaDeshabilitados;
	}
	
	for each (Usuario ^ usuario in listaBusqueda) {
		bool coincideNombre = (String::IsNullOrEmpty(nombre) || usuario->GetNombre() == nombre);
		bool coincideEstado = (String::IsNullOrEmpty(estado) || usuario->GetEstadoCuenta() == estado);

		if (coincideNombre && coincideEstado) {
			resultados->Add(usuario);
		}
	}

	return resultados;
}