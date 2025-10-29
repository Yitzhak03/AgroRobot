#include "Insumo.h"
#include "Almacen.h"
namespace AgroRobotModel {
	using namespace System;
	public ref class StockInsumo {
	public:
		property int Id;
		property Insumo^ Insumoo;
		property Almacen^ Almacenn;
		property float Stock;
		StockInsumo();
		StockInsumo(
			int id,
			Insumo^ insumoo,
			Almacen^ almacenn,
			float stock
		);
	};
}