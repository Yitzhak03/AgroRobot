#include "BaseController.h"

using namespace AgroRobotController;
using namespace System::IO;

BaseController::BaseController() {
	this->objConexion = gcnew SqlConnection();
}

SqlConnection^ BaseController::getObjConexion() {
	return this->objConexion;
}

/*Procedimiento: Se abre conexión*/
void BaseController::abrirConexion() {
	/*cambien la base de dato*/
	this->objConexion->ConnectionString = "Server=200.16.7.140;DataBase=a20232054;User id=a20232054;Password=P34YpxZ2";

	this->objConexion->Open();
}

/*Procedimiento: Se cierra la conexión*/
void BaseController::cerrarConexion() {
	this->objConexion->Close();
}

/*Procedimiento 1*/
SqlDataReader^ BaseController::executeStoredProcedureReader(String^ tipoProcedimiento, array<SqlParameter^>^ parametros) {
	try {
		abrirConexion();
		SqlCommand^ comando = gcnew SqlCommand(tipoProcedimiento, this->getObjConexion());
		comando->CommandType = System::Data::CommandType::StoredProcedure;

		if (tipoProcedimiento != nullptr) {
			for each (SqlParameter ^ param in parametros) {
				comando->Parameters->Add(param);
			}
		}

		return comando->ExecuteReader();
	}
	catch (Exception^ ex) {
		Console::WriteLine("Error al ejecutar el tipo de procedimiento almacenado: " + ex->Message);
		cerrarConexion();
		return nullptr;
	}
}

/*Procedimiento 2*/
bool BaseController::executeStoredProcedure(String^ tipoProcedimiento, array<SqlParameter^>^ parametros) {
	try {
		abrirConexion();
		SqlCommand^ comando = gcnew SqlCommand(tipoProcedimiento, this->getObjConexion());
		comando->CommandType = System::Data::CommandType::StoredProcedure;

		// Agregar parámetros si existen
		if (parametros != nullptr) {
			for each (SqlParameter ^ param in parametros) {
				comando->Parameters->Add(param);
			}
		}

		comando->ExecuteNonQuery();
		cerrarConexion();
		return true;
	}
	catch (Exception^ ex) {
		Console::WriteLine("Error al ejecutar el tipo de procedimiento almacenado: " + ex->Message);
		cerrarConexion();
		return false;
	}
}

/*Procedimiento 3*/
int BaseController::executeStoredProcedureScalar(String^ tipoProcedimiento, array<SqlParameter^>^ parametros) {
	try {
		abrirConexion();
		SqlCommand^ comando = gcnew SqlCommand(tipoProcedimiento, this->getObjConexion());
		comando->CommandType = System::Data::CommandType::StoredProcedure;

		if (parametros != nullptr) {
			for each (SqlParameter ^ param in parametros) {
				comando->Parameters->Add(param);
			}
		}

		Object^ result = comando->ExecuteScalar();
		cerrarConexion();

		if (result != nullptr && result != DBNull::Value) {
			return Convert::ToInt32(result);
		}
		return 0;
	}
	catch (Exception^ ex) {
		Console::WriteLine("Error al ejecutar el tipo deprocedimiento almacenado: " + ex->Message);
		cerrarConexion();
		return 0;
	}
}