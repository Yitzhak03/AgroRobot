#include "ReporteInsumosXalmacen.h"
using namespace AgroRobotModel;
ReporteInsumosXalmacen::ReporteInsumosXalmacen()
{
}
ReporteInsumosXalmacen::ReporteInsumosXalmacen(String^ nombre, int cantInsumos)
{
	Nombre = nombre;
	CantInsumos = cantInsumos;
}