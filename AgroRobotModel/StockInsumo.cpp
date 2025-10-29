#include "StockInsumo.h"
using namespace AgroRobotModel;
StockInsumo::StockInsumo() {
	//Id = 0;
	//Insumoo = gcnew Insumo();
	//Almacenn = gcnew Almacen();
	//Stock = 0.0f;
}
StockInsumo::StockInsumo(
	int id,
	Insumo^ insumoo,
	Almacen^ almacenn,
	float stock
) 
{
	Id = id;
	Insumoo = insumoo;
	Almacenn = almacenn;
	Stock = stock;
}