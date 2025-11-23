#pragma once

namespace AgroRobotController {
	using namespace System;
	using namespace System::Data::SqlClient;

	public ref class BaseController {
	private:
		SqlConnection^ objConexion;

	public:
		/*Constructor*/
		BaseController();

		/*Obtención del objeto de conexión*/
		SqlConnection^ getObjConexion();

		/*Abrir conexión*/
		void abrirConexion();

		/*Cerrar conexión*/
		void cerrarConexion();

		/*Obtener registros de la BD*/
		SqlDataReader^ executeStoredProcedureReader(String^ tipoProcedimiento, array<SqlParameter^>^ parametros);

		/*Verifica si una operación se hizo sin errores*/
		bool executeStoredProcedure(String^ tipoProcedimiento, array<SqlParameter^>^ parametros);

		/*Ejecución de una operación y devuelve el valor de la primera columna de la primera fila*/
		int executeStoredProcedureScalar(String^ tipoProcedimiento, array<SqlParameter^>^ parametros);
	};

}

