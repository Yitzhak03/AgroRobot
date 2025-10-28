#include "Insumo.h"

using namespace AgroRobotModel;

Insumo::Insumo() {

}

Insumo::Insumo(
    int id,
    String^ nombre,
    String^ tipo,
    float stock,
	String^ unidad
) 
{
	Id = id;
	Nombre = nombre;
	Tipo = tipo;
	Stock = stock;
	Unidad = unidad;
}
