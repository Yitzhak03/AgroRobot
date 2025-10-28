#pragma once
namespace AgroRobotModel {
    using namespace System;
    public ref class Insumo {
    public:
        property int Id;
        property String^ Nombre;
        property String^ Tipo;
		property float Stock;
        property String^ Unidad;
        Insumo();
        Insumo(
            int id,
            String^ nombre,
            String^ tipo,
            float stock,
            String^ unidad
        );
    };
}