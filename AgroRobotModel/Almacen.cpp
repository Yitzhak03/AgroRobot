#include "Almacen.h"
using namespace AgroRobotModel;

Almacen::Almacen()
{
}

Almacen::Almacen(
	int id,
	String^ nombre,
	String^ ubicacion
)
{
	Id = id;
	Nombre = nombre;
	Ubicacion = ubicacion;
}
