#include "Insumo.h"

using namespace AgroRobotModel;

Insumo::Insumo() {

}

Insumo::Insumo(
    int id,
    String^ nombre,
    String^ tipo,
    String^ stockActual,
    String^ stockMinimo,
    Alerta^ alertasInsumo) 
{
	Id = id;
	Nombre = nombre;
	Tipo = tipo;
	StockActual = stockActual;
	StockMinimo = stockMinimo;
	AlertasInsumo = alertasInsumo;
}
