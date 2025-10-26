#pragma once
#include "Alerta.h"
namespace AgroRobotModel {
    using namespace System;
    public ref class Insumo {
    public:
        property int Id;
        property String^ Nombre;
        property String^ Tipo;
        property String^ StockActual;
        property String^ StockMinimo;
        property Alerta^ AlertasInsumo;
        Insumo();
        Insumo(
            int id,
            String^ nombre,
            String^ tipo,
            String^ stockActual,
            String^ stockMinimo,
            Alerta^ alertasInsumo
        );
    };
}