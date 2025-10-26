#pragma once
#include "Insumo.h"
namespace AGROModel {
    using namespace System;
	using namespace System::Collections::Generic;
    public ref class Almacen {
    public: 
        property int Id;
        property String^ Nombre;
        property String^ Ubicacion;
        property String^ Capacidad;
        property String^ ZonasAlmacenamiento;
		property List<Insumo^>^ InsumosAlmacenados;
        Almacen();
        Almacen(
            int id,
            String^ nombre,
            String^ ubicacion,
            String^ capacidad,
            String^ zonasAlmacenamiento,
            List<Insumo^>^ insumosAlmacenados
        );
    };
}
