#include "AlmacenController.h"
using namespace AgroRobotController;
using namespace System::IO;
using namespace System;
using namespace System::Runtime::Serialization::Formatters::Binary;
AlmacenController::AlmacenController()
{
	this->listaOrdenes = gcnew List<OrdenDistribucion^>();

	if (!File::Exists("ordenes.txt")) {
		File::WriteAllText("ordenes.txt", "");
	}
	//this->cargarOrdenesDesdeArchivo();
}

// ========================Métodos para base de datos========================

// Método para leer los almacenes desde la base de datos
List<Almacen^>^ AlmacenController::read_BD(){
	//Creacion de la lista para almacenar los almacenes
	List<Almacen^>^ listaAlmacenes = gcnew List<Almacen^>();
	abrirConexion();
	String^ sql = "Select * from Almacenes;";
	SqlCommand^ comando = gcnew SqlCommand(sql, this->objConexion);
	SqlDataReader^ data = comando->ExecuteReader();
	while (data->Read()) {
		int id = safe_cast<int>(data[0]);
		String^ nombre = safe_cast<String^>(data[1]);
		String^ ubicacion = safe_cast<String^>(data[2]);
		Almacen^ almacen = gcnew Almacen(id, nombre, ubicacion);
		listaAlmacenes->Add(almacen);
	}
	cerrarConexion();
	data->Close();
	return listaAlmacenes;
}
// Método para agregar un nuevo almacén a la base de datos
void AlmacenController::agregarAlmacen_BD(Almacen^ almacen){
	String^ nombre = almacen->Nombre;
	String^ ubicacion = almacen->Ubicacion;
	abrirConexion();
	String^ sql = "INSERT INTO Almacenes (nombre,ubicacion) VALUES ('" + nombre + "','" + ubicacion + "')";
	SqlCommand^ comando = gcnew SqlCommand(sql, this->objConexion);
	comando->ExecuteNonQuery();
	cerrarConexion();
}
// Método para buscar un almacén por su ID en la base de datos
Almacen^ AlmacenController::buscarPorId_BD(int id){
	// Crear el objeto para almacenar el almacén encontrado 
	Almacen^ almacen = nullptr;
	abrirConexion();
	String^ sql = "SELECT * FROM Almacenes WHERE id=" + id + ";";
	SqlCommand^ comando = gcnew SqlCommand(sql, this->objConexion);
	SqlDataReader^ data = comando->ExecuteReader();
	if (data->Read()) {
		int id = safe_cast<int>(data[0]);
		String^ nombre = safe_cast<String^>(data[1]);
		String^ ubicacion = safe_cast<String^>(data[2]);
		almacen = gcnew Almacen(id, nombre, ubicacion);
	}
	cerrarConexion();
	data->Close();
	return almacen;
}
// Método para buscar el nombre de un almacén por su ID en la base de datos
String^ AlmacenController::buscarNombrePorId_BD(int id){
	abrirConexion();
	String^ sql = "SELECT nombre FROM Almacenes WHERE id=" + id + ";";
	SqlCommand^ comando = gcnew SqlCommand(sql, this->objConexion);
	SqlDataReader^ data = comando->ExecuteReader();
	String^ nombre = "";
	if (data->Read()) {
		nombre = safe_cast<String^>(data[0]);
	}
	cerrarConexion();
	data->Close();
	return nombre;
}
// Método para buscar el ID de un almacén por su nombre en la base de datos
int AlmacenController::buscarIdPorNombre_BD(String^ nombre){
	abrirConexion();
	String^ sql = "SELECT id FROM Almacenes WHERE nombre='" + nombre + "';";
	SqlCommand^ comando = gcnew SqlCommand(sql, this->objConexion);
	SqlDataReader^ data = comando->ExecuteReader();
	int id = -1;
	if (data->Read()) {
		id = safe_cast<int>(data[0]);
	}
	cerrarConexion();
	data->Close();
	return id;
}
// Método para obtener los nombres de todos los almacenes desde la base de datos
List<String^>^ AlmacenController::obtenerNombresAlmacenes_BD(){
	// Crear la lista para almacenar los nombres
	List<String^>^ nombres = gcnew List<String^>();
	abrirConexion();
	String^ sql = "SELECT nombre FROM Almacenes;";
	SqlCommand^ comando = gcnew SqlCommand(sql, this->objConexion);
	SqlDataReader^ data = comando->ExecuteReader();
	while (data->Read()) {
		String^ nombre = safe_cast<String^>(data[0]);
		nombres->Add(nombre);
	}
	cerrarConexion();
	data->Close();
	return nombres;
}
// Método para obtener un almacén por su nombre desde la base de datos
Almacen^ AlmacenController::obtenerAlmacenPorNombre_BD(String^ nombre){
	// Crear el objeto para almacenar el almacén encontrado
	Almacen^ almacen = nullptr;
	abrirConexion();
	String^ sql = "SELECT * FROM Almacenes WHERE nombre='" + nombre + "';";
	SqlCommand^ comando = gcnew SqlCommand(sql, this->objConexion);
	SqlDataReader^ data = comando->ExecuteReader();
	if (data->Read()) {
		int id = safe_cast<int>(data[0]);
		String^ nombre = safe_cast<String^>(data[1]);
		String^ ubicacion = safe_cast<String^>(data[2]);
		almacen = gcnew Almacen(id, nombre, ubicacion);
	}
	cerrarConexion();
	data->Close();
	return almacen;
}

//============================ Otros métodos ============================

void AlmacenController::guardarOrdenesEnArchivo() {
	List<String^>^ lineas = gcnew List<String^>();
	for each (OrdenDistribucion ^ orden in this->listaOrdenes) {
		String^ linea = orden->Id + ";" +
			orden->IdDieta + ";" +
			orden->RobotAsignado + ";" +
			orden->FechaHoraEntrega + ";" +
			orden->Ruta + ";" +
			orden->Prioridad;
		lineas->Add(linea);
	}
	File::WriteAllLines("ordenes.txt", lineas->ToArray());
}
void AlmacenController::cargarOrdenesDesdeArchivo() {
	this->listaOrdenes = gcnew List<OrdenDistribucion^>(); // Inicializar la lista

	try {
		abrirConexion();

		// 1. Crear la consulta SQL
		String^ sSqlOrdenes = "SELECT Id, IdDieta, RobotAsignado, FechaHoraEntrega, Ruta, Prioridad ";
		sSqlOrdenes += " FROM OrdenesDistribucion ";

		SqlCommand^ comando = gcnew SqlCommand(sSqlOrdenes, getObjConexion());
		SqlDataReader^ objData = comando->ExecuteReader();

		// 2. Leer los registros
		while (objData->Read()) {
			int id = objData->GetInt32(0);
			int idDieta = objData->GetInt32(1);
			String^ robot = objData->GetString(2)->Trim();
			String^ fecha = objData->GetString(3)->Trim();
			String^ ruta = objData->GetString(4)->Trim();
			String^ prioridad = objData->GetString(5)->Trim();

			// Nota: Se asume que los campos para 'Animal^', 'Dieta^' e 'List<Insumo^>'
			// se cargan o inicializan aparte o son pasados como nulos por ahora.
			OrdenDistribucion^ orden = gcnew OrdenDistribucion(id, idDieta, robot, fecha, ruta, prioridad, nullptr, nullptr, gcnew List<Insumo^>());
			this->listaOrdenes->Add(orden);
		}

		objData->Close();
		cerrarConexion();
	}
	catch (Exception^ ex) {
		// Manejo de errores de conexión o SQL
		Console::WriteLine("Error al cargar órdenes desde la base de datos: " + ex->Message);
		this->listaOrdenes = gcnew List<OrdenDistribucion^>();
	}
}
bool AlmacenController::registrarOrden(OrdenDistribucion^ orden) {
	// 1. Agregar a la lista en memoria
	this->listaOrdenes->Add(orden);

	// 2. Crear la sentencia SQL para inserción
	String^ sSqlOrden = "INSERT INTO OrdenesComida (Id, IdDieta, RobotAsignado, FechaHoraEntrega, Ruta, Prioridad) ";
	sSqlOrden += " VALUES(" + orden->Id + ", ";
	sSqlOrden += " " + orden->IdDieta + ", "; // IdDieta es INT, sin comillas
	sSqlOrden += " '" + orden->RobotAsignado + "', ";
	sSqlOrden += " '" + orden->FechaHoraEntrega + "', ";
	sSqlOrden += " '" + orden->Ruta + "', ";
	sSqlOrden += " '" + orden->Prioridad + "')";

	// 3. Ejecutar el SQL (se asume que executeSql devuelve el número de filas afectadas o un booleano)
	int filasAfectadas = executeSql(sSqlOrden);

	if (filasAfectadas > 0)
		return true;
	else {
		// Opcional: Si falla la BD, remover de la lista en memoria
		this->listaOrdenes->Remove(orden);
		return false;
	}
}
List <OrdenDistribucion^>^ AlmacenController::listarOrdenes() {
	return this->listaOrdenes;
}
void AlmacenController::escribirArchivoBINOrdenes() {
	Stream^ stream = File::Open(this->archivoOrdenes, FileMode::Create);
	BinaryFormatter^ formateador = gcnew BinaryFormatter();
	formateador->Serialize(stream, this->listaOrdenes);
	stream->Close();
}
// **Función para agregar a AlmacenController.cpp**
int AlmacenController::obtenerMaximoIdOrden() {
	int maxId = 0;
	try {
		abrirConexion();
		// SQL: Obtiene el Id más alto. Si no hay registros, devuelve NULL.
		String^ sSqlMaxId = "SELECT MAX(Id) FROM OrdenesDistribucion";
		SqlCommand^ comando = gcnew SqlCommand(sSqlMaxId, getObjConexion());
		Object^ resultado = comando->ExecuteScalar(); // Ejecuta y devuelve un único valor

		if (resultado != nullptr && resultado != DBNull::Value) {
			maxId = Convert::ToInt32(resultado);
		}
		cerrarConexion();
	}
	catch (Exception^ ex) {
		Console::WriteLine("Error al obtener MaxId: " + ex->Message);
		// Si hay error, asumimos 0.
		return 0;
	}
	return maxId;
}