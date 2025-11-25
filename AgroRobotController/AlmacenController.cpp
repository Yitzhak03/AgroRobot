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
	this->cargarOrdenesDesdeArchivo();
}

List<Almacen^>^ AlmacenController::readTxt()
{
	// Leer txt de la forma:
	// Id(int);Nombre(String^);Ubicacion(String^)
	List<Almacen^>^ lista = gcnew List<Almacen^>();
	String^ path = "almacenes.txt";
	array<String^>^ lineas = File::ReadAllLines(path);
	for each (String ^ linea in lineas) {
		array<String^>^ datos = linea->Split(';');
		Almacen^ almacen = gcnew Almacen();
		almacen->Id = Convert::ToInt32(datos[0]);
		almacen->Nombre = datos[1];
		almacen->Ubicacion = datos[2];
		lista->Add(almacen);
	}
	return lista;
}

void AlmacenController::writeTxt(List<Almacen^>^ lista)
{
	String^ path = "almacenes.txt";
	List<String^>^ lineas = gcnew List<String^>();
	for each (Almacen ^ a in lista) {
		String^ linea = Convert::ToString(a->Id) + ";" + a->Nombre + ";" + a->Ubicacion;
		lineas->Add(linea);
	}
	File::WriteAllLines(path, lineas->ToArray());
}

Almacen^ AlmacenController::buscarPorId(int id)
{
	List<Almacen^>^ lista = readTxt();
	for each (Almacen ^ a in lista) {
		if (a->Id == id) {
			return a;
		}
	}
	return nullptr;
}

void AlmacenController::agregarAlmacen(Almacen^ almacen)
{
	List<Almacen^>^ lista = readTxt();
	lista->Add(almacen);
	// Escribir de nuevo el archivo
	writeTxt(lista);
}

int AlmacenController::generarNuevoId()
{
	List<Almacen^>^ lista = readTxt();
	int maxId = -1;
	for each (Almacen ^ a in lista) {
		if (a->Id > maxId) {
			maxId = a->Id;
		}
	}
	return maxId + 1;
}
List<String^>^ AlmacenController::obtenerNombresAlmacenes()
{
	List<Almacen^>^ lista = readTxt();
	List<String^>^ nombres = gcnew List<String^>();
	for each (Almacen ^ a in lista) {
		nombres->Add(a->Nombre);
	}
	return nombres;
}
Almacen^ AlmacenController::obtenerAlmacenPorNombre(String^ nombre)
{
	List<Almacen^>^ lista = readTxt();
	for each (Almacen ^ a in lista) {
		if (a->Nombre == nombre) {
			return a;
		}
	}
	return nullptr;
}
String^ AlmacenController::buscarNombrePorId(int id)
{
	List<Almacen^>^ lista = readTxt();
	for each (Almacen ^ a in lista) {
		if (a->Id == id) {
			return a->Nombre;
		}
	}
	return "";
}
int AlmacenController::buscarIdPorNombre(String^ nombre)
{
	List<Almacen^>^ lista = readTxt();
	for each (Almacen ^ a in lista) {
		if (a->Nombre == nombre) {
			return a->Id;
		}
	}
	return -1;
}
//=====================================OTROS=================================================
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