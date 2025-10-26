#include "Reporte.h"

using namespace AgroRobotModel;

Reporte::Reporte() {

}

Reporte::Reporte(
	int idReporte,
	String^ tipo,
	String^ fechaGeneracion,
	String^ contenido) 
{
	IdReporte = idReporte;
	Tipo = tipo;
	FechaGeneracion = fechaGeneracion;
	Contenido = contenido;
}
