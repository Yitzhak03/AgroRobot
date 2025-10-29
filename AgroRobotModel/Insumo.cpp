#include "Insumo.h"

using namespace AgroRobotModel;

Insumo::Insumo() {

}

Insumo::Insumo(
    int id,
    String^ nombre,
    String^ tipo,
	String^ unidad
) 
{
	Id = id;
	Nombre = nombre;
	Tipo = tipo;
	Unidad = unidad;
}
