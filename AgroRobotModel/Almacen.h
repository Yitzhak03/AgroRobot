#pragma once
#include "Insumo.h"
namespace AgroRobotModel {
    using namespace System;
	using namespace System::Collections::Generic;
    public ref class Almacen {
    public: 
        property int Id;
        property String^ Ubicacion;
        property float Capacidad;
		property List<Insumo^>^ Insumos;
        Almacen();
        Almacen(
            int id,
            String^ ubicacion,
            float capacidad,
            List<Insumo^>^ insumos
        );
    };
}
