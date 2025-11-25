#include "UsuarioController.h"
#include "RolController.h"

using namespace AgroRobotController;
using namespace System::IO;
using namespace System::Runtime::Serialization::Formatters::Binary;

UsuarioController::UsuarioController(){
	this->listaUsuarios = gcnew List<Usuario^>();
	
	/*
	String^ path = "usuarios.txt";

	/*crea el txt de habilitados 
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
	*/

	try {
		// Paso1: Establecer la conexion
		abrirConexion();

		// Paso2: Crear el comando SQL
		String^ sSqlUsuarios = "SELECT Id, Nombre, Email, Contrasenha, UltimoAcceso, EstadoCuenta, IdRol ";
		sSqlUsuarios += " FROM Usuarios ";

		// Paso3: Crear el SqlCommand, donde le paso la sentencia SQL y la conexion
		SqlCommand^ comando = gcnew SqlCommand(sSqlUsuarios, getObjConexion());

		// Paso4: Ahora para ejecutar voy a utilizar ExecuteReader cuando la sentencia es SELECT
		SqlDataReader^ objData = comando->ExecuteReader();

		// Paso5: Leer los registros de la tabla
		while (objData->Read()) {
			int id = objData->GetInt32(0); // Id
			String^ nombre = objData->GetString(1)->Trim(); // Nombre
			String^ email = objData->GetString(2)->Trim(); // Email
			String^ contrasenha = objData->GetString(3)->Trim(); // Contrasenha
			String^ ultimoAcceso = objData->GetString(4)->Trim(); // UltimoAcceso
			String^ estadoCuentaString = objData->GetString(5)->Trim();
			bool estadoCuenta = false;
			if (String::Equals(estadoCuentaString, "True", StringComparison::OrdinalIgnoreCase)) {
				estadoCuenta = true;
			}
			int idRol = objData->GetInt32(6); // IdRol
			// Obtener el Rol asociado
			RolController^ rolController = gcnew RolController();
			Rol^ rol = rolController->obtenerRolPorId(idRol);
			Usuario^ usuario = gcnew Usuario(id, nombre, email, contrasenha, ultimoAcceso, estadoCuenta, rol);
			this->listaUsuarios->Add(usuario);
		}
		// Paso6: Cerrar el DataReader y la conexion
		objData->Close();
		cerrarConexion();
	}
	catch (Exception^ ex) {
		Console::WriteLine("Error al conectar a la base de datos: " + ex->Message);
		// En caso de cualquier error, crear lista vacía
		this->listaUsuarios = gcnew List<Usuario^>();
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

bool UsuarioController::agregarUsuario(Usuario^ usuario){
	this->listaUsuarios->Add(usuario);
	//escribirArchivo();
	
	String^ sSqlUsuario = "INSERT INTO Usuarios (Id, Nombre, Email, Contrasenha, UltimoAcceso, EstadoCuenta) ";
	sSqlUsuario += " VALUES(" + usuario->GetId() + ", ";
	sSqlUsuario += " '" + usuario->GetNombre() + "', ";
	sSqlUsuario += " '" + usuario->GetEmail() + "', ";
	sSqlUsuario += " '" + usuario->GetContrasenha() + "', ";
	sSqlUsuario += " '" + usuario->GetUltimoAcceso() + "', ";
	sSqlUsuario += " '" + usuario->GetEstadoCuenta() + "')";
	int idDieta = insertSql(sSqlUsuario);
	if (idDieta > 0)
		return true;
	else
		return false;
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

void UsuarioController::cambiarEstadoUsuario(int id) {
	// 1. Obtener el usuario de la lista/memoria (asumiendo que sigue siendo necesario por si se usa en la UI/código)
	Usuario^ usuario = obtenerUsuarioPorId(id);

	if (usuario != nullptr) {
		// Determinar el nuevo estado
		// invierte el estado actual del objeto Usuario en memoria
		bool nuevoEstado = !usuario->GetEstadoCuenta();

		// Actualizar el objeto Usuario en memoria
		usuario->SetEstadoCuenta(nuevoEstado);

		// Construir la consulta SQL para actualizar el estado en la base de datos
		String^ sSqlUsuario = "UPDATE Usuarios SET EstadoCuenta = ";

		// Convertir el booleano 'nuevoEstado' a un valor que la base de datos entienda (p.ej., 1 o 0)
		// En el ejemplo de INSERT usaste '"+ usuario->GetEstadoCuenta() +"', 
		// por lo que asumo que tu base de datos acepta directamente la representación string del booleano.
		sSqlUsuario += " '" + nuevoEstado.ToString() + "' ";
		sSqlUsuario += " WHERE Id = " + id;

		// Ejecutar la consulta SQL de actualización
		int filasAfectadas = executeSql(sSqlUsuario);

	}
}

void UsuarioController::actualizarUsuario(Usuario^ usuario)
{
	//  Actualizar el objeto Usuario en la lista en memoria (Lógica existente)
	for (int i = 0; i < this->listaUsuarios->Count; ++i) {
		if (this->listaUsuarios[i]->GetId() == usuario->GetId()) {
			this->listaUsuarios[i] = usuario;
			break;
		}
	}

	String^ sSqlUsuario = "UPDATE Usuarios SET ";
	sSqlUsuario += " Nombre = '" + usuario->GetNombre() + "', ";
	sSqlUsuario += " Email = '" + usuario->GetEmail() + "', ";
	// Nota: Si la contraseña no se cambia en esta acción, es mejor no incluirla
	// o usar un procedimiento almacenado. La incluyo basándome en tu INSERT previo.
	sSqlUsuario += " Contrasenha = '" + usuario->GetContrasenha() + "', ";
	sSqlUsuario += " UltimoAcceso = '" + usuario->GetUltimoAcceso() + "', ";
	// EstadoCuenta puede o no actualizarse, pero se incluye para una actualización completa.
	sSqlUsuario += " EstadoCuenta = '" + usuario->GetEstadoCuenta() + "' ";
	sSqlUsuario += " WHERE Id = " + usuario->GetId();

	// 3. Ejecutar la consulta SQL (Usando la función 'ejecutarSql' hipotética)
	int filasAfectadas = executeSql(sSqlUsuario);
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

void UsuarioController::escribirArchivoBINUsuarios() {
	//Creamos el archivo
	Stream^ stream = File::Open(this->archivo, FileMode::Create);
	BinaryFormatter^ formateador = gcnew BinaryFormatter();
	formateador->Serialize(stream, this->listaUsuarios);
	stream->Close();
}