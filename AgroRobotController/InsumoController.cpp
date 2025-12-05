#include "InsumoController.h"
using namespace AgroRobotController;
using namespace System::IO;
using namespace System;
InsumoController::InsumoController()
{
}
// Métodos para base de datos
List<Insumo^>^ InsumoController::read_BD()
{
	// Creacion de la lista para almacenar los insumos
	List<Insumo^>^ listaInsumos = gcnew List<Insumo^>();
	// Abrir conexión
	abrirConexion();
	// Consulta SQL
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
	// Cerrar conexión
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