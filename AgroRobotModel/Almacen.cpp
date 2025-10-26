#include "Almacen.h"

using namespace AGROModel;

Almacen::Almacen()
{
}

Almacen::Almacen(
	int id,
	String^ nombre,
	String^ ubicacion,
	String^ capacidad,
	String^ zonasAlmacenamiento,
	List<Insumo^>^ insumosAlmacenados
)
{
	Id = id;
	Nombre = nombre;
	Ubicacion = ubicacion;
	Capacidad = capacidad;
	ZonasAlmacenamiento = zonasAlmacenamiento;
	InsumosAlmacenados = insumosAlmacenados;
}
