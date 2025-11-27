#include "RolController.h"

using namespace AgroRobotController;
using namespace System::IO;
using namespace System::Runtime::Serialization::Formatters::Binary;

RolController::RolController(){
	this->listaRoles = gcnew List<Rol^>();

	String^ path = "roles.txt";
	
	if (!File::Exists(path)) {
		File::WriteAllText(path, "");
	}
	
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
		rol->SetPermisos(listaPermisos);
		listaRoles->Add(rol);
	}

	/*try {
		// Paso1: Establecer la conexion
		abrirConexion();
		// Paso2: Crear el comando SQL
		String^ sSqlRoles = "SELECT Id, Nombre, Permisos ";
		sSqlRoles += " FROM Roles ";
		// Paso3: Crear el SqlCommand, donde le paso la sentencia SQL y la conexion
		SqlCommand^ comando = gcnew SqlCommand(sSqlRoles, getObjConexion());
		// Paso4: Ahora para ejecutar voy a utilizar ExecuteReader cuando la sentencia es SELECT
		// Para recuperar la informacion que me devuelve un select, utilizo SqlDataReader
		SqlDataReader^ objData = comando->ExecuteReader();
		// Paso5: Leer los registros de la tabla
		while (objData->Read()) {
			int id = objData->GetInt32(0); // Id
			String^ nombre = objData->GetString(1); // Nombre
			/*bool listaPermisosNull = objData->IsDBNull(2); // Permisos puede ser null
			List<bool>^ listaPermisos = gcnew List<bool>();
			if (!listaPermisosNull) {
				String^ permisosTxt = objData->GetString(2); // Permisos
				array<String^>^ permisosBoolean = permisosTxt->Split('|');
				for each (String ^ permisoBool in permisosBoolean)
					listaPermisos->Add(Convert::ToBoolean(Convert::ToInt32(permisoBool)));
			}
			else listaPermisos = nullptr;
			String^ permisosString = objData->GetString(2); // Permisos
			List<bool>^ permisos = ConvertirStringAPermisos(permisosString);

			Rol^ rol = gcnew Rol(id, nombre);
			rol->SetPermisos(permisos);
			this->listaRoles->Add(rol);
		}
		// Paso6: Cerrar el DataReader y la conexion
		objData->Close();
		cerrarConexion();
	}
	catch (Exception^ ex) {
		Console::WriteLine("Error al conectar a la base de datos: " + ex->Message);
		// En caso de cualquier error, crear lista vacía
		this->listaRoles = gcnew List<Rol^>();
	}*/

}

void RolController::escribirArchivo(){
	String^ path = "roles.txt";
	// Preparamos el array de líneas con la misma cantidad que la lista
	array<String^>^ lineasArchivo = gcnew array<String^>(this->listaRoles->Count);
	for (int i = 0; i < this->listaRoles->Count; ++i) {
		Rol^ rol = this->listaRoles[i];
		lineasArchivo[i] = rol->GetId() + ";" + rol->GetNombre() + ";";

		// Convertir la lista de permisos a formato "1|0|1|0"
		List<bool>^ permisos = rol->GetPermisos();
		String^ permisosTxt = "";
		
		for (int j = 0; j < permisos->Count; ++j) {
			if (permisos[j]) {
				permisosTxt += "1";
			}
			else {
				permisosTxt += "0";
			}
			
			if (j < permisos->Count - 1) permisosTxt += "|";
		}

		// Linea completa
		lineasArchivo[i] = rol->GetId() + ";" + rol->GetNombre() + ";" + permisosTxt;
	}
	// Escribimos todas las líneas al archivo 
	File::WriteAllLines(path, lineasArchivo);
}

void RolController::agregarRol(Rol^ rol) {
	this->listaRoles->Add(rol);
	escribirArchivo();

	/*String^ permisosTxt = ConvertirPermisosAString(rol->GetPermisos()); // ASUMIMOS ESTO

	String^ sSqlRol = "INSERT INTO Roles (Id, Nombre, ListaPermisos) ";
	sSqlRol += " VALUES(" + rol->GetId() + ", ";
	sSqlRol += " '" + rol->GetNombre() + "', ";
	sSqlRol += " '" + permisosTxt + "')"; // <<-- COMPLETAR LA SENTENCIA INSERT

	// Nota: Debes usar executeSql o insertSql aquí.
	int filasAfectadas = executeSql(sSqlRol);
	if (filasAfectadas > 0)
		return true;
	else
		return false;*/
}

bool RolController::eliminarRol(int id) {
	Rol^ rol = obtenerRolPorId(id);
	if (rol != nullptr) {
		this->listaRoles->Remove(rol);
		//escribirArchivo();
		//return true;
		String^ sSqlRoles = "DELETE FROM Roles WHERE Id = " + id;
		return executeSql(sSqlRoles);
	}
	return false;
}

bool RolController::modificarRol(int id, String^ nombre, List<bool>^ listaPermisos) {
	// 1. Obtener el objeto Rol de la lista en memoria
	Rol^ rol = obtenerRolPorId(id);

	if (rol != nullptr) {
		// 2. Actualizar el objeto Rol en memoria
		rol->SetNombre(nombre);
		rol->SetPermisos(listaPermisos);
		escribirArchivo();
		return true;

		/*/ 3. Convertir la lista de permisos a un string para la BD (ej: "1|0|1|1")
		// Esta función debe estar definida en el controlador.
		String^ permisosTxt = ConvertirPermisosAString(listaPermisos);

		// 4. Construir la consulta SQL para la base de datos
		String^ sSqlRol = "UPDATE Roles SET ";
		sSqlRol += " Nombre = '" + nombre + "', ";
		// Asegúrate de que el nombre de la columna sea 'ListaPermisos'
		sSqlRol += " ListaPermisos = '" + permisosTxt + "' ";
		sSqlRol += " WHERE Id = " + id;

		// 5. Ejecutar la consulta SQL (usando la función que maneja la BD)
		return executeSql(sSqlRol);*/
	}
	return false;
}

Rol^ RolController::obtenerRolPorId(int id){
	for each (Rol ^ rol in this->listaRoles) {
		if (rol->Id == id) {
			return rol;
		}
	}
}

Rol^ RolController::obtenerRolPorNombre(String^ nombre) {
	for each (Rol ^ rol in this->listaRoles) {
		if (rol->Nombre == nombre) {
			return rol;
		}
	}
}

List<Rol^>^ RolController::obtenerTodosRoles() {
	return this->listaRoles;
}

List<bool>^ RolController::ConvertirStringAPermisos(String^ permisosString)
{
	List<bool>^ listaPermisos = gcnew List<bool>();

	// Usamos 'Split' para dividir la cadena por el delimitador '|'
	array<String^>^ arrayPermisos = permisosString->Split('|');

	// Recorremos cada elemento del array resultante
	for each (String ^ permiso in arrayPermisos)
	{
		// El 'permiso' será "1" o "0"
		if (permiso == "1")
		{
			listaPermisos->Add(true);
		}
		else // Asume que cualquier otro valor es "0" o false
		{
			listaPermisos->Add(false);
		}
	}

	return listaPermisos;
}

void RolController::escribirArchivoBINRoles() {
	//Creamos el archivo
	Stream^ stream = File::Open(this->archivo, FileMode::Create);
	BinaryFormatter^ formateador = gcnew BinaryFormatter();
	formateador->Serialize(stream, this->listaRoles);
	stream->Close();
}

String^ RolController::ConvertirPermisosAString(List<bool>^ listaPermisos)
{
	String^ permisosTxt = "";

	if (listaPermisos == nullptr) return ""; // Manejar el caso nulo

	for (int j = 0; j < listaPermisos->Count; ++j) {
		if (listaPermisos[j]) {
			permisosTxt += "1";
		}
		else {
			permisosTxt += "0";
		}

		if (j < listaPermisos->Count - 1) permisosTxt += "|"; // Usar el separador '|'
	}
	return permisosTxt;
}