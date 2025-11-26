#include "UsuarioController.h"
#include "RolController.h"

using namespace AgroRobotController;
using namespace System::IO;
using namespace System::Runtime::Serialization::Formatters::Binary;

// ==========================================================================
//  INTERRUPTOR MAESTRO DE DATOS
//  1 = MODO BASE DE DATOS (SQL Server) -> Úsenlo en la pucp
//  0 = MODO TEXTO (usuarios.txt)       -> Úsenlo en sus casitas
// ==========================================================================
#define USAR_BASE_DE_DATOS 1  // <--- cambien este número según el modo deseado


UsuarioController::UsuarioController() {
	this->listaUsuarios = gcnew List<Usuario^>();

#if USAR_BASE_DE_DATOS
	// ====================================================
	// LÓGICA: BASE DE DATOS SQL
	// ====================================================
	try {
		abrirConexion();
		String^ sSqlUsuarios = "SELECT Id, Nombre, Email, Contrasenha, UltimoAcceso, EstadoCuenta, IdRol FROM Usuarios ";
		SqlCommand^ comando = gcnew SqlCommand(sSqlUsuarios, getObjConexion());
		SqlDataReader^ objData = comando->ExecuteReader();

		while (objData->Read()) {
			int id = objData->GetInt32(0);
			String^ nombre = objData->GetString(1)->Trim();
			String^ email = objData->GetString(2)->Trim();
			String^ contrasenha = objData->GetString(3)->Trim();
			String^ ultimoAcceso = objData->GetString(4)->Trim();
			String^ estadoCuentaString = objData->GetString(5)->Trim();

			bool estadoCuenta = false;
			if (String::Equals(estadoCuentaString, "True", StringComparison::OrdinalIgnoreCase)) {
				estadoCuenta = true;
			}

			int idRol = objData->GetInt32(6);

			RolController^ rolController = gcnew RolController();
			Rol^ rol = rolController->obtenerRolPorId(idRol);

			Usuario^ usuario = gcnew Usuario(id, nombre, email, contrasenha, ultimoAcceso, estadoCuenta, rol);
			this->listaUsuarios->Add(usuario);
		}
		objData->Close();
		cerrarConexion();
	}
	catch (Exception^ ex) {
		Console::WriteLine("Error SQL: " + ex->Message);
		// Si falla SQL, la lista queda vacía
	}

#else
	// ====================================================
	// LÓGICA: ARCHIVO DE TEXTO (OFFLINE)
	// ====================================================
	String^ path = "usuarios.txt";
	if (!File::Exists(path)) File::WriteAllText(path, "");

	try {
		array<String^>^ lineas = File::ReadAllLines(path);
		for each (String ^ linea in lineas) {
			if (String::IsNullOrWhiteSpace(linea)) continue;
			array<String^>^ datos = linea->Split(';');
			if (datos->Length < 7) continue; // Validación básica

			int id = Convert::ToInt32(datos[0]);
			String^ nombre = datos[1];
			String^ email = datos[2];
			String^ contrasenha = datos[3];
			String^ ultimoAcceso = datos[4];
			bool estadoCuenta = Convert::ToBoolean(datos[5]);
			int idRol = Convert::ToInt32(datos[6]);

			Rol^ rol;
			try {
				RolController^ rc = gcnew RolController();
				rol = rc->obtenerRolPorId(idRol);
			}
			catch (Exception^) { rol = gcnew Rol(idRol, "RolTxt"); }

			Usuario^ user = gcnew Usuario(id, nombre, email, contrasenha, ultimoAcceso, estadoCuenta, rol);
			listaUsuarios->Add(user);
		}
	}
	catch (Exception^) {}
#endif
}

void UsuarioController::escribirArchivo() {
	// Esta función solo sirve para el modo texto, pero la dejamos por si acaso
	String^ path = "usuarios.txt";
	List<Usuario^>^ lista = this->listaUsuarios;
	array<String^>^ lineasArchivo = gcnew array<String^>(lista->Count);

	for (int i = 0; i < lista->Count; ++i) {
		Usuario^ u = lista[i];
		int idRol = (u->GetRol() != nullptr) ? u->GetRol()->GetId() : 3;
		lineasArchivo[i] = u->GetId() + ";" + u->GetNombre() + ";" + u->GetEmail() + ";" +
			u->GetContrasenha() + ";" + u->GetUltimoAcceso() + ";" + u->GetEstadoCuenta() + ";" + idRol;
	}
	File::WriteAllLines(path, lineasArchivo);
}

bool UsuarioController::agregarUsuario(Usuario^ usuario) {
	this->listaUsuarios->Add(usuario);

#if USAR_BASE_DE_DATOS
	// --- MODO SQL ---
	String^ sSqlUsuario = "INSERT INTO Usuarios (Id, Nombre, Email, Contrasenha, UltimoAcceso, EstadoCuenta, IdRol) ";
	sSqlUsuario += " VALUES(" + usuario->GetId() + ", ";
	sSqlUsuario += " '" + usuario->GetNombre() + "', ";
	sSqlUsuario += " '" + usuario->GetEmail() + "', ";
	sSqlUsuario += " '" + usuario->GetContrasenha() + "', ";
	sSqlUsuario += " '" + usuario->GetUltimoAcceso() + "', ";
	sSqlUsuario += " '" + usuario->GetEstadoCuenta() + "', ";
	sSqlUsuario += " " + usuario->GetRol()->GetId() + ")";

	int res = insertSql(sSqlUsuario);
	return (res > 0);
#else
	// --- MODO TXT ---
	escribirArchivo();
	return true;
#endif
}

void UsuarioController::actualizarUsuario(Usuario^ usuario) {
	// Actualizar en memoria siempre
	for (int i = 0; i < this->listaUsuarios->Count; ++i) {
		if (this->listaUsuarios[i]->GetId() == usuario->GetId()) {
			this->listaUsuarios[i] = usuario;
			break;
		}
	}

#if USAR_BASE_DE_DATOS
	// --- MODO SQL ---
	String^ sSqlUsuario = "UPDATE Usuarios SET ";
	sSqlUsuario += " Nombre = '" + usuario->GetNombre() + "', ";
	sSqlUsuario += " Email = '" + usuario->GetEmail() + "', ";
	sSqlUsuario += " Contrasenha = '" + usuario->GetContrasenha() + "', ";
	sSqlUsuario += " UltimoAcceso = '" + usuario->GetUltimoAcceso() + "', ";
	sSqlUsuario += " EstadoCuenta = '" + usuario->GetEstadoCuenta() + "' ";
	sSqlUsuario += " WHERE Id = " + usuario->GetId();

	executeSql(sSqlUsuario);
#else
	// --- MODO TXT ---
	escribirArchivo();
#endif
}

void UsuarioController::cambiarEstadoUsuario(int id) {
	Usuario^ usuario = obtenerUsuarioPorId(id);
	if (usuario != nullptr) {
		bool nuevoEstado = !usuario->GetEstadoCuenta();
		usuario->SetEstadoCuenta(nuevoEstado);

#if USAR_BASE_DE_DATOS
		// --- MODO SQL ---
		String^ sSqlUsuario = "UPDATE Usuarios SET EstadoCuenta = '" + nuevoEstado.ToString() + "' WHERE Id = " + id;
		executeSql(sSqlUsuario);
#else
		// --- MODO TXT ---
		escribirArchivo();
#endif
	}
}

// --- MÉTODOS COMUNES (No dependen de la BD) ---

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

Usuario^ UsuarioController::obtenerUsuarioPorId(int id) {
	for each (Usuario ^ usuario in this->listaUsuarios) {
		if (usuario->GetId() == id) return usuario;
	}
	return nullptr;
}

List<Usuario^>^ UsuarioController::obtenerUsuarioPorNombreEstado(String^ nombre, Nullable<bool> estado) {
	List<Usuario^>^ resultados = gcnew List<Usuario^>();
	List<Usuario^>^ listaBusqueda;

	if (!estado.HasValue) listaBusqueda = this->listaUsuarios;
	else listaBusqueda = (estado.Value) ? obtenerUsuariosHabilitados() : obtenerUsuariosDeshabilitados();

	for each (Usuario ^ usuario in listaBusqueda) {
		bool coincideNombre = (String::IsNullOrEmpty(nombre) || usuario->GetNombre() == nombre);
		bool coincideEstado = (!estado.HasValue || usuario->GetEstadoCuenta() == estado.Value);

		if (coincideNombre && coincideEstado) {
			resultados->Add(usuario);
		}
	}
	return resultados;
}

void UsuarioController::escribirArchivoBINUsuarios() {
	Stream^ stream = File::Open(this->archivo, FileMode::Create);
	BinaryFormatter^ formateador = gcnew BinaryFormatter();
	formateador->Serialize(stream, this->listaUsuarios);
	stream->Close();
}