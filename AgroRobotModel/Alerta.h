#pragma once
#include "Reporte.h"
namespace AgroRobotModel {
    using namespace System;
    public ref class Alerta {
    public: 
        property int Id;
        property String^ Tipo;
        property String^ FechaHora;
        property String^ Mensaje;
        property String^ EstadoAtencion;
		property Reporte^ ReporteAsociado;
        Alerta();
        Alerta(
            int id,
            String^ tipo,
            String^ fechaHora,
            String^ mensaje,
            String^ estadoAtencion,
            Reporte^ reporteAsociado
        );
    };
}
