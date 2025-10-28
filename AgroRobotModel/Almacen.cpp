#include "Almacen.h"

using namespace AgroRobotModel;

Almacen::Almacen()
{
}

Almacen::Almacen(
	int id,
	String^ ubicacion,
	float capacidad,
	List<Insumo^>^ insumos
)
{
	Id = id;
	Ubicacion = ubicacion;
	Capacidad = capacidad;
	Insumos = insumos;
}
