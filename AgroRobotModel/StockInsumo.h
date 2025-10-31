#include "Insumo.h"
//#include "Almacen.h"
namespace AgroRobotModel {
	ref class Almacen; // Forward declaration
	using namespace System;
	public ref class StockInsumo {
	public:
		property int Id;
		property Insumo^ Insumoo;
		property Almacen^ Almacenn;
		property float Stock;
		property float LimiteBajo;
		property float LimiteAlto;
		StockInsumo();
		StockInsumo(
			int id,
			Insumo^ insumoo,
			Almacen^ almacenn,
			float stock,
			float limiteBajo,
			float limiteAlto
		);
	};
}