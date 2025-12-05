#include "StockInsumoController.h"
#include "InsumoController.h"
#include "AlmacenController.h"
using namespace AgroRobotController;
using namespace System::IO;
StockInsumoController::StockInsumoController(){}
//List<StockInsumo^>^ StockInsumoController::readTxt()
//{
//	// Leer txt de la forma:
//	// Id(int);IdInsumo(int);IdAlmacen(int);Stock(String^);LimiteBajo(String^);LimiteAlto(String^)
//	List<StockInsumo^>^ lista = gcnew List<StockInsumo^>();
//	String^ path = "stocks.txt";
//	array<String^>^ lineas = File::ReadAllLines(path);
//	for each (String ^ linea in lineas) {
//		array<String^>^ datos = linea->Split(';');
//		StockInsumo^ stockInsumo = gcnew StockInsumo();
//		stockInsumo->Id = Convert::ToInt32(datos[0]);
//		InsumoController^ insumoController = gcnew InsumoController();
//		stockInsumo->Insumoo = insumoController->buscarPorId(Convert::ToInt32(datos[1]));
//		AlmacenController^ almacenController = gcnew AlmacenController();
//		stockInsumo->Almacenn = almacenController->buscarPorId(Convert::ToInt32(datos[2]));
//		stockInsumo->Stock = Convert::ToSingle(datos[3]);
//		stockInsumo->LimiteBajo = Convert::ToSingle(datos[4]);
//		stockInsumo->LimiteAlto = Convert::ToSingle(datos[5]);
//		lista->Add(stockInsumo);
//	}
//	return lista;
//}
//void StockInsumoController::writeTxt(List<StockInsumo^>^ lista)
//{
//	String^ path = "stocks.txt";
//	List<String^>^ lineas = gcnew List<String^>();
//	for each (StockInsumo ^ s in lista) {
//		String^ linea = Convert::ToString(s->Id) + ";" +
//			Convert::ToString(s->Insumoo->Id) + ";" +
//			Convert::ToString(s->Almacenn->Id) + ";" +
//			Convert::ToString(s->Stock) + ";" +
//			Convert::ToString(s->LimiteBajo) + ";" +
//			Convert::ToString(s->LimiteAlto);
//		lineas->Add(linea);
//	}
//	File::WriteAllLines(path, lineas->ToArray());
//}
//int StockInsumoController::generarNuevoId()
//{
//	List<StockInsumo^>^ lista = readTxt();
//	int maxId = 0;
//	for each (StockInsumo ^ s in lista) {
//		if (s->Id > maxId) {
//			maxId = s->Id;
//		}
//	}
//	return maxId + 1;
//}
//StockInsumo^ StockInsumoController::buscarPorId(int id)
//{
//	List<StockInsumo^>^ lista = readTxt();
//	for each (StockInsumo ^ s in lista) {
//		if (s->Id == id) {
//			return s;
//		}
//	}
//	return nullptr;
//}
//void StockInsumoController::agregarStockInsumo(StockInsumo^ stockInsumo)
//{
//	List<StockInsumo^>^ lista = readTxt();
//	lista->Add(stockInsumo);
//	// Escribir de nuevo el archivo
//	writeTxt(lista);
//}
//void StockInsumoController::actualizarStockInsumo(StockInsumo^ stockInsumo)
//{
//	List<StockInsumo^>^ lista = readTxt();
//	for (int i = 0; i < lista->Count; i++) {
//		if (lista[i]->Id == stockInsumo->Id) {
//			lista[i] = stockInsumo;
//			break;
//		}
//	}
//	// Escribir de nuevo el archivo
//	writeTxt(lista);
//}
//List<StockInsumo^>^ StockInsumoController::buscarPorIdInsumo(int idInsumo)
//{
//	List<StockInsumo^>^ lista = readTxt();
//	List<StockInsumo^>^ resultados = gcnew List<StockInsumo^>();
//	for each (StockInsumo ^ s in lista) {
//		if (s->Insumoo->Id == idInsumo) {
//			resultados->Add(s);
//		}
//	}
//	return resultados;
//}
//List<StockInsumo^>^ StockInsumoController::buscarPorIdAlmacen(int idAlmacen)
//{
//	List<StockInsumo^>^ lista = readTxt();
//	List<StockInsumo^>^ resultados = gcnew List<StockInsumo^>();
//	for each (StockInsumo ^ s in lista) {
//		if (s->Almacenn->Id == idAlmacen) {
//			resultados->Add(s);
//		}
//	}
//	return resultados;
//}
//StockInsumo^ StockInsumoController::buscarPorIdInsumoYAlmacen(int idInsumo, int idAlmacen)
//{
//	List<StockInsumo^>^ lista = readTxt();
//	for each (StockInsumo ^ s in lista) {
//		if (s->Insumoo->Id == idInsumo && s->Almacenn->Id == idAlmacen) {
//			return s;
//		}
//	}
//	return nullptr;
//}
//int StockInsumoController::cantidadInsumosEnAlmacen(int idAlmacen)
//{
//	List<StockInsumo^>^ lista = readTxt();
//	int contador = 0;
//	for each (StockInsumo ^ s in lista) {
//		if (s->Almacenn->Id == idAlmacen) {
//			contador++;
//		}
//	}
//	return contador;
//}

// ================= Metodo para base de datos ================= 

// Obtener todos los registros de la tabla
List<StockInsumo^>^ StockInsumoController::read_BD(){
	// Creacion de la lista para almacenar los Stocks
	List<StockInsumo^>^ listaStocks = gcnew List<StockInsumo^>();
	// Abrir conexión
	abrirConexion();
	// Consulta SQL
	String^ sql = "SELECT * FROM StockInsumos;";
	SqlCommand^ comando = gcnew SqlCommand(sql, this->objConexion);
	SqlDataReader^ data = comando->ExecuteReader();
	while (data->Read()) {
		int idStock = safe_cast<int>(data[0]);
		int idInsumo = safe_cast<int>(data[1]);
		int idAlmacen = safe_cast<int>(data[2]);
		float stock = Convert::ToSingle(data[3]);
		float limiteBajo = Convert::ToSingle(data[4]);
		float limiteAlto = Convert::ToSingle(data[5]);
		StockInsumo^ stockInsumo = gcnew StockInsumo(
			idStock,
			(gcnew InsumoController())->buscarPorId_BD(idInsumo),
			(gcnew AlmacenController())->buscarPorId_BD(idAlmacen),
			stock,
			limiteBajo,
			limiteAlto);
		listaStocks->Add(stockInsumo);
	}
	// Cerrar conexión
	cerrarConexion();
	data->Close();
	return listaStocks;
}
// Agregar un nuevo registro a la tabla
void StockInsumoController::agregarStockInsumo_BD(StockInsumo^ stockInsumo){
	// Obtener los datos del objeto stockInsumo
	int idInsumo = stockInsumo->Insumoo->Id;
	int idAlmacen = stockInsumo->Almacenn->Id;
	float stock = stockInsumo->Stock;
	float limiteBajo = stockInsumo->LimiteBajo;
	float limiteAlto = stockInsumo->LimiteAlto;
	// Abrir conexión
	abrirConexion();
	// Consulta SQL
	String^ sql = "INSERT INTO StockInsumos (IdInsumo, IdAlmacen, Stock, LimiteBajo, LimiteAlto) " +
		"VALUES (" + idInsumo + ", " + idAlmacen + ", " + stock + ", " + limiteBajo + ", " + limiteAlto + ");";
	SqlCommand^ comando = gcnew SqlCommand(sql, this->objConexion);
	comando->ExecuteNonQuery();
	// Cerrar conexión
	cerrarConexion();
}
// Actualizar un registro existente en la tabla
void StockInsumoController::actualizarStockInsumo_BD(StockInsumo^ stockInsumo){
	// Obtener los datos del objeto stockInsumo
	int idStock = stockInsumo->Id;
	int idInsumo = stockInsumo->Insumoo->Id;
	int idAlmacen = stockInsumo->Almacenn->Id;
	float stock = stockInsumo->Stock;
	float limiteBajo = stockInsumo->LimiteBajo;
	float limiteAlto = stockInsumo->LimiteAlto;
	// Abrir conexión
	abrirConexion();
	// Consulta SQL
	String^ sql = "UPDATE StockInsumos SET " +
		"IdInsumo = " + idInsumo + ", " +
		"IdAlmacen = " + idAlmacen + ", " +
		"Stock = " + stock + ", " +
		"LimiteBajo = " + limiteBajo + ", " +
		"LimiteAlto = " + limiteAlto + " " +
		"WHERE Id = " + idStock + ";";
	SqlCommand^ comando = gcnew SqlCommand(sql, this->objConexion);
	comando->ExecuteNonQuery();
	// Cerrar conexión
	cerrarConexion();
}
// Buscar un registro por su Id
StockInsumo^ StockInsumoController::buscarPorId_BD(int id){
	// Abrir conexión
	abrirConexion();
	// Consulta SQL
	String^ sql = "SELECT * FROM StockInsumos WHERE Id = " + id + ";";
	SqlCommand^ comando = gcnew SqlCommand(sql, this->objConexion);
	SqlDataReader^ data = comando->ExecuteReader();
	// Crear el objeto StockInsumo a retornar
	StockInsumo^ stockInsumo = nullptr;
	while (data->Read()) {
		int idStock = safe_cast<int>(data[0]);
		int idInsumo = safe_cast<int>(data[1]);
		int idAlmacen = safe_cast<int>(data[2]);
		float stock = Convert::ToSingle(data[3]);
		float limiteBajo = Convert::ToSingle(data[4]);
		float limiteAlto = Convert::ToSingle(data[5]);
		stockInsumo = gcnew StockInsumo(
			idStock,
			(gcnew InsumoController())->buscarPorId_BD(idInsumo),
			(gcnew AlmacenController())->buscarPorId_BD(idAlmacen),
			stock,
			limiteBajo,
			limiteAlto);
	}
	// Cerrar conexión
	cerrarConexion();
	data->Close();
	return stockInsumo;
}
// Buscar un registro por su IdInsumo
List<StockInsumo^>^ StockInsumoController::buscarPorIdInsumo_BD(int idInsumo){
	// Abrir conexión
	abrirConexion();
	// Consulta SQL
	String^ sql = "SELECT * FROM StockInsumos WHERE IdInsumo = " + idInsumo + ";";
	SqlCommand^ comando = gcnew SqlCommand(sql, this->objConexion);
	SqlDataReader^ data = comando->ExecuteReader();
	// Crear la lista de StockInsumo a retornar
	List<StockInsumo^>^ listaStocks = gcnew List<StockInsumo^>();
	while (data->Read()) {
		int idStock = safe_cast<int>(data[0]);
		int idInsumo = safe_cast<int>(data[1]);
		int idAlmacen = safe_cast<int>(data[2]);
		float stock = Convert::ToSingle(data[3]);
		float limiteBajo = Convert::ToSingle(data[4]);
		float limiteAlto = Convert::ToSingle(data[5]);
		StockInsumo^ stockInsumo = gcnew StockInsumo(
			idStock,
			(gcnew InsumoController())->buscarPorId_BD(idInsumo),
			(gcnew AlmacenController())->buscarPorId_BD(idAlmacen),
			stock,
			limiteBajo,
			limiteAlto);
		listaStocks->Add(stockInsumo);
	}
	// Cerrar conexión
	cerrarConexion();
	data->Close();
	return listaStocks;
}
// Buscar un registro por su IdAlmacen
List<StockInsumo^>^ StockInsumoController::buscarPorIdAlmacen_BD(int idAlmacen){
	// Abrir conexión
	abrirConexion();
	// Consulta SQL
	String^ sql = "SELECT * FROM StockInsumos WHERE IdAlmacen = " + idAlmacen + ";";
	SqlCommand^ comando = gcnew SqlCommand(sql, this->objConexion);
	SqlDataReader^ data = comando->ExecuteReader();
	// Crear la lista de StockInsumo a retornar
	List<StockInsumo^>^ listaStocks = gcnew List<StockInsumo^>();
	while (data->Read()) {
		int idStock = safe_cast<int>(data[0]);
		int idInsumo = safe_cast<int>(data[1]);
		int idAlmacen = safe_cast<int>(data[2]);
		float stock = Convert::ToSingle(data[3]);
		float limiteBajo = Convert::ToSingle(data[4]);
		float limiteAlto = Convert::ToSingle(data[5]);
		StockInsumo^ stockInsumo = gcnew StockInsumo(
			idStock,
			(gcnew InsumoController())->buscarPorId_BD(idInsumo),
			(gcnew AlmacenController())->buscarPorId_BD(idAlmacen),
			stock,
			limiteBajo,
			limiteAlto);
		listaStocks->Add(stockInsumo);
	}
	// Cerrar conexión
	cerrarConexion();
	data->Close();
	return listaStocks;
}
// Buscar un registro por su IdInsumo y IdAlmacen
StockInsumo^ StockInsumoController::buscarPorIdInsumoYAlmacen_BD(int idInsumo, int idAlmacen){
	// Abrir conexión
	abrirConexion();
	// Consulta SQL
	String^ sql = "SELECT * FROM StockInsumos WHERE IdInsumo = " + idInsumo + " AND IdAlmacen = " + idAlmacen + ";";
	SqlCommand^ comando = gcnew SqlCommand(sql, this->objConexion);
	SqlDataReader^ data = comando->ExecuteReader();
	// Crear el objeto StockInsumo a retornar
	StockInsumo^ stockInsumo = nullptr;
	while (data->Read()) {
		int idStock = safe_cast<int>(data[0]);
		int idInsumo = safe_cast<int>(data[1]);
		int idAlmacen = safe_cast<int>(data[2]);
		float stock = Convert::ToSingle(data[3]);
		float limiteBajo = Convert::ToSingle(data[4]);
		float limiteAlto = Convert::ToSingle(data[5]);
		stockInsumo = gcnew StockInsumo(
			idStock,
			(gcnew InsumoController())->buscarPorId_BD(idInsumo),
			(gcnew AlmacenController())->buscarPorId_BD(idAlmacen),
			stock,
			limiteBajo,
			limiteAlto);
	}
	// Cerrar conexión
	cerrarConexion();
	data->Close();
	return stockInsumo;
}
// Contar la cantidad de insumos en un almacén específico
int StockInsumoController::cantidadInsumosEnAlmacen_BD(int idAlmacen){
	// Abrir conexión
	abrirConexion();
	// Consulta SQL
	String^ sql = "SELECT COUNT(*) FROM StockInsumos WHERE IdAlmacen = " + idAlmacen + ";";
	SqlCommand^ comando = gcnew SqlCommand(sql, this->objConexion);
	int cantidad = Convert::ToInt32(comando->ExecuteScalar());
	// Cerrar conexión
	cerrarConexion();
	return cantidad;
}