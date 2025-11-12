#include "UsuarioController.h"
#include "RolController.h"

using namespace AgroRobotController;
using namespace System::IO;

UsuarioController::UsuarioController(){
	this->listaUsuarios = gcnew List<Usuario^>();
	
	String^ path = "usuarios.txt";

	/*crea el txt de habilitados */
	if (!File::Exists(path)) {
		File::WriteAllText(path, "");
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
		bool estadoCuenta = Convert::ToBoolean(datos[5]);
		
		int idRol = Convert::ToInt32(datos[6]);
		RolController^ rolController = gcnew RolController();
		Rol^ rol = rolController->obtenerRolPorId(idRol);
		
		Usuario^ user = gcnew Usuario(id, nombre, email, contrasenha, ultimoAcceso, estadoCuenta, rol);
		listaUsuarios->Add(user);
	}
}

void UsuarioController::escribirArchivo(){
	String^ path = "usuarios.txt";

	// Preparamos el array de líneas con la misma cantidad que la lista
	List<Usuario^>^ lista = this->listaUsuarios;

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
	escribirArchivo();
}


List<Usuario^>^ UsuarioController::obtenerUsuariosPorEstado(Nullable<bool> estado) {
    List<Usuario^>^ listaResultados = gcnew List<Usuario^>();

    for each (Usuario ^ usuario in this->listaUsuarios) {
        if (!estado.HasValue || usuario->GetEstadoCuenta() == estado.Value) {
            listaResultados->Add(usuario);
        }
    }
    return listaResultados;
}

List<Usuario^>^ UsuarioController::obtenerUsuariosHabilitados() {
	return obtenerUsuariosPorEstado(true);
}

List<Usuario^>^ UsuarioController::obtenerUsuariosDeshabilitados() {
	return obtenerUsuariosPorEstado(false);
}


void UsuarioController::cambiarEstadoUsuario(int id){
	Usuario^ usuario = obtenerUsuarioPorId(id);

	if (usuario != nullptr) {
		if (usuario->GetEstadoCuenta()) {
			usuario->SetEstadoCuenta(false);
		}
		else {
			usuario->SetEstadoCuenta(true);
		}
		escribirArchivo();
	}
}

void UsuarioController::actualizarUsuario(Usuario^ usuario)
{
	for (int i = 0; i < this->listaUsuarios->Count; ++i) {
		if (this->listaUsuarios[i]->GetId() == usuario->GetId() ) {
			this->listaUsuarios[i] = usuario;
			break;
		}
	}
	escribirArchivo();
}

Usuario^ UsuarioController::obtenerUsuarioPorId(int id){
	for each (Usuario ^ usuario in this->listaUsuarios) {
		if (usuario->GetId() == id) {
			return usuario;
		}
	}
	return nullptr;
}

List<Usuario^>^ UsuarioController::obtenerUsuarioPorNombreEstado(String^ nombre, Nullable<bool> estado){
	List<Usuario^>^ resultados = gcnew List<Usuario^>();
	List<Usuario^>^ listaBusqueda = gcnew List<Usuario^>();

	/*si no se escoge estado se busca en ambos, si se escoge se busca solo en una de ellas*/
	if (!estado.HasValue) {
		listaBusqueda = this->listaUsuarios;
	}
	else {
		listaBusqueda = (estado.Value) ? obtenerUsuariosHabilitados() : obtenerUsuariosDeshabilitados();
	}
	
	for each (Usuario ^ usuario in listaBusqueda) {
		bool coincideNombre = (String::IsNullOrEmpty(nombre) || usuario->GetNombre() == nombre);
		bool coincideEstado = (!estado.HasValue || usuario->GetEstadoCuenta() == estado.Value);

		if (coincideNombre && coincideEstado) {
			resultados->Add(usuario);
		}
	}

	return resultados;
}