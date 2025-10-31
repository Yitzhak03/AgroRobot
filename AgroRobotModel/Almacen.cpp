#include "Almacen.h"
#include "StockInsumo.h" // include real porque aquí necesitamos la definición completa
using namespace AgroRobotModel;

Almacen::Almacen()
{
}

Almacen::Almacen(
	int id,
	String^ nombre,
	String^ ubicacion,
	List<StockInsumo^>^ stocks
)
{
	Id = id;
	Nombre = nombre;
	Ubicacion = ubicacion;
	Stocks = stocks;
}
