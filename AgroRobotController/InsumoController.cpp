#include "InsumoController.h"
using namespace AgroRobotController;
using namespace System::IO;
using namespace System;
InsumoController::InsumoController()
{
}
List<Insumo^>^ InsumoController::readTxt()
{
	List<Insumo^>^ lista = gcnew List<Insumo^>();
	String^ path = "insumos.txt";
	array<String^>^ lineas = File::ReadAllLines(path);
	for each (String ^ linea in lineas) {
		if (String::IsNullOrWhiteSpace(linea)) continue;
		array<String^>^ datos = linea->Split(';');
		Insumo^ insumo = gcnew Insumo();
		insumo->Id = Convert::ToInt32(datos[0]);
		insumo->Nombre = datos[1];
		insumo->Tipo = datos[2];
		insumo->Unidad = datos[3];
		lista->Add(insumo);
	}
	return lista;
}
void InsumoController::writeTxt(List<Insumo^>^ lista)
{
	String^ path = "insumos.txt";
	// Preparamos el array de líneas con la misma cantidad que la lista
	array<String^>^ lineas = gcnew array<String^>(lista->Count);
	for (int i = 0; i < lista->Count; ++i) {
		Insumo^ insumo = lista[i];
		lineas[i] = String::Format("{0};{1};{2};{3}",
			insumo->Id,
			insumo->Nombre,
			insumo->Tipo,
			insumo->Unidad
		);
	}
	// Escribimos todas las líneas al archivo (sobrescribe)
	File::WriteAllLines(path, lineas);
}
void InsumoController::agregarInsumo(Insumo^ insumo)
{
	List<Insumo^>^ lista = readTxt();
	lista->Add(insumo);
	writeTxt(lista);
}
void InsumoController::eliminarInsumo(int id)
{
	List<Insumo^>^ lista = readTxt();
	for (int i = 0; i < lista->Count; ++i) {
		if (lista[i]->Id == id) {
			lista->RemoveAt(i);
			break;
		}
	}
	writeTxt(lista);
}
void InsumoController::actualizarInsumo(Insumo^ insumo)
{
	List<Insumo^>^ lista = readTxt();
	for (int i = 0; i < lista->Count; ++i) {
		if (lista[i]->Id == insumo->Id) {
			lista[i] = insumo;
			break;
		}
	}
	writeTxt(lista);
}
Insumo^ InsumoController::buscarPorId(int id)
{
	List<Insumo^>^ lista = readTxt();
	for each (Insumo ^ insumo in lista) {
		if (insumo->Id == id) {
			return insumo;
		}
	}
	return nullptr;
}
List<Insumo^>^ InsumoController::buscarPorTipo(String^ tipo)
{
	List<Insumo^>^ lista = readTxt();
	List<Insumo^>^ resultados = gcnew List<Insumo^>();
	for each (Insumo ^ insumo in lista) {
		if (insumo->Tipo->Equals(tipo, StringComparison::OrdinalIgnoreCase)) {
			resultados->Add(insumo);
		}
	}
	return resultados;
}
List<String^>^ InsumoController::obtenerTiposInsumos()
{
	List<Insumo^>^ lista = readTxt();
	List<String^>^ tipos = gcnew List<String^>();
	for each (Insumo ^ insumo in lista) {
		if (!tipos->Contains(insumo->Tipo)) {
			tipos->Add(insumo->Tipo);
		}
	}
	return tipos;
}
int InsumoController::generarNuevoId()
{
	List<Insumo^>^ lista = readTxt();
	int maxId = 0;
	for each (Insumo ^ insumo in lista) {
		if (insumo->Id > maxId) {
			maxId = insumo->Id;
		}
	}
	return maxId + 1;
}
// Métodos para base de datos
List<Insumo^>^ InsumoController::read_BD()
{
	//Creacion de la lista para almacenar los insumos
	List<Insumo^>^ listaInsumos = gcnew List<Insumo^>();
	abrirConexion();
	String^ sql = "Select * from Insumos;";
	SqlCommand^ comando = gcnew SqlCommand(sql, this->objConexion);
	SqlDataReader^ data = comando->ExecuteReader();
	while (data->Read()) {
		int id = safe_cast<int>(data[0]);
		String^ nombre = safe_cast<String^>(data[1]);
		String^ tipo = safe_cast<String^>(data[2]);
		String^ unidad = safe_cast<String^>(data[3]);
		Insumo^ insumo = gcnew Insumo(id, nombre, tipo, unidad);
		listaInsumos->Add(insumo);
	}
	cerrarConexion();
	data->Close();
	return listaInsumos;
}
void InsumoController::agregarInsumo_BD(Insumo^ insumo)
{
	String^ nombre = insumo->Nombre;
	String^ tipo = insumo->Tipo;
	String^ unidad = insumo->Unidad;
	abrirConexion();
	String^ sql = "insert into Insumos(nombre,tipo,unidad) values ('" + nombre + "','" + tipo + "','" + unidad + "')";
	SqlCommand^ comando = gcnew SqlCommand(sql, this->objConexion);
	comando->ExecuteNonQuery();
	cerrarConexion();
}
void InsumoController::eliminarInsumo_BD(int id)
{
	abrirConexion();
	String^ sql = "delete from Insumos where id=" + id.ToString();
	SqlCommand^ sentenciaSQL = gcnew SqlCommand(sql, this->objConexion);
	sentenciaSQL->ExecuteNonQuery();
	cerrarConexion();
}
void InsumoController::actualizarInsumo_BD(Insumo^ insumo)
{
	int id = insumo->Id;
	String^ nombre = insumo->Nombre;
	String^ tipo = insumo->Tipo;
	String^ unidad = insumo->Unidad;
	abrirConexion();
	String^ sql = "update Insumos set nombre='" + nombre + "', tipo='" + tipo + "', unidad='" + unidad + "' where id=" + id;
	SqlCommand^ comando = gcnew SqlCommand(sql, this->objConexion);
	comando->ExecuteNonQuery();
	cerrarConexion();
}
Insumo^ InsumoController::buscarPorId_BD(int id){
	abrirConexion();
	String^ sql = "Select * from Insumos where id=" + id + ";";
	SqlCommand^ comando = gcnew SqlCommand(sql, this->objConexion);
	SqlDataReader^ data = comando->ExecuteReader();
	//Declaracion de variable
	Insumo^ insumo = nullptr;
	while (data->Read()) {
		String^ nombre = safe_cast<String^>(data[1]);
		String^ tipo = safe_cast<String^>(data[2]);
		String^ unidad = safe_cast<String^>(data[3]);
		insumo = gcnew Insumo(id, nombre, tipo, unidad);
	}
	cerrarConexion();
	data->Close();
	return insumo;
}
List<Insumo^>^ InsumoController::buscarPorTipo_BD(String^ tipo){
	//Creacion de la lista para almacenar los insumos
	List<Insumo^>^ listaInsumos = gcnew List<Insumo^>();
	abrirConexion();
	String^ sql = "Select * from Insumos where tipo='" + tipo + "';";
	SqlCommand^ comando = gcnew SqlCommand(sql, this->objConexion);
	SqlDataReader^ data = comando->ExecuteReader();
	while (data->Read()) {
		int id = safe_cast<int>(data[0]);
		String^ nombre = safe_cast<String^>(data[1]);
		String^  unidad = safe_cast<String^>(data[3]);
		Insumo^ insumo = gcnew Insumo(id, nombre, tipo, unidad);
		listaInsumos->Add(insumo);
	}
	cerrarConexion();
	data->Close();
	return listaInsumos;
}
List<String^>^ InsumoController::obtenerTiposInsumos_BD(){
	//Creacion de la lista para almacenar los tipos de insumos
	List<String^>^ tiposInsumos = gcnew List<String^>();
	abrirConexion();
	String^ sql = "Select DISTINCT tipo from Insumos;";
	SqlCommand^ comando = gcnew SqlCommand(sql, this->objConexion);
	SqlDataReader^ data = comando->ExecuteReader();
	String^ tipo;
	while (data->Read()) {
		tipo = safe_cast<String^>(data[0]);
		tiposInsumos->Add(tipo);
	}
	cerrarConexion();
	data->Close();
	return tiposInsumos;

}