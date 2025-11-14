#pragma once
namespace AgroRobotModel {
    using namespace System;
    public ref class ReporteInsumosXalmacen {
    public:
        //Eje X
        property String^ Nombre;
		//Eje Y
        property int CantInsumos;
        ReporteInsumosXalmacen();
        ReporteInsumosXalmacen(
            String^ nombre,
            int cantInsumos
        );
    };
}