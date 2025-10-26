#pragma once
namespace AGROModel {
    using namespace System;

    public ref class Reporte {
    public: 
        property int IdReporte;
        property String^ Tipo;
        property String^ FechaGeneracion;
        property String^ Contenido;
        Reporte();
        Reporte(
            int idReporte,
            String^ tipo,
            String^ fechaGeneracion,
            String^ contenido
        );
    };
}