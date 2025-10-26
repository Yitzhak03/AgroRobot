#include "Alerta.h"

using namespace AgroRobotModel;

Alerta::Alerta() {

}

Alerta::Alerta(
	int id,
	String^ tipo,
	String^ fechaHora,
	String^ mensaje,
	String^ estadoAtencion,
	Reporte^ reporteAsociado) 
{
	Id = id;
	Tipo = tipo;
	FechaHora = fechaHora;
	Mensaje = mensaje;
	EstadoAtencion = estadoAtencion;
	ReporteAsociado = reporteAsociado;
}
