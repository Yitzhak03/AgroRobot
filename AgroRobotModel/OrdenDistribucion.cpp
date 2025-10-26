#include "OrdenDistribucion.h"

using namespace AGROModel;

OrdenDistribucion::OrdenDistribucion() {

}

OrdenDistribucion::OrdenDistribucion(
    int id,
    int idDieta,
    String^ robotAsignado,
    String^ fechaHoraEntrega,
    String^ ruta,
    String^ prioridad,
    ConfiguracionSistema^ configuracion,
	Almacen^ almacenOrigen,
	List<Insumo^>^ insumos)
{
	Id = id;
	IdDieta = idDieta;
	RobotAsignado = robotAsignado;
	FechaHoraEntrega = fechaHoraEntrega;
	Ruta = ruta;
	Prioridad = prioridad;
	Configuracion = configuracion;
	AlmacenOrigen = almacenOrigen;
	Insumos = insumos;
}
