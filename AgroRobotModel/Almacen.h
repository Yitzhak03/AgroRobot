#pragma once
namespace AgroRobotModel {
    using namespace System;
    using namespace System::Collections::Generic;
    public ref class Almacen {
    public:
        property int Id;
        property String^ Nombre;
        property String^ Ubicacion;
        Almacen();
        Almacen(
            int id,
            String^ nombre,
            String^ ubicacion
        );
    };
}
