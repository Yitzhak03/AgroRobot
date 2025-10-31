#pragma once
//#include "StockInsumo.h"
namespace AgroRobotModel {
	ref class StockInsumo; // Forward declaration
    using namespace System;
	using namespace System::Collections::Generic;
    public ref class Almacen {
    public: 
        property int Id;
        property String^ Nombre;
        property String^ Ubicacion;
		property List<StockInsumo^>^ Stocks;
        Almacen();
        Almacen(
            int id,
            String^ nombre,
            String^ ubicacion,
            List<StockInsumo^>^ stocks
        );
    };
}
