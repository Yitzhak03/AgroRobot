#pragma once
namespace AgroRobotModel {
    using namespace System;
    using namespace System::Collections::Generic;

    // Forward declarations
    ref class ConfiguracionSistema;
    ref class Almacen;
    ref class Insumo;

    public ref class OrdenDistribucion {
    public:
        property int Id;
        property int IdDieta;
        property String^ RobotAsignado;
        property String^ FechaHoraEntrega;
        property String^ Ruta;
        property String^ Prioridad;
        property ConfiguracionSistema^ Configuracion;
        property Almacen^ AlmacenOrigen;
        property List<Insumo^>^ Insumos;
        OrdenDistribucion();
        OrdenDistribucion(
            int id,
            int idDieta,
            String^ robotAsignado,
            String^ fechaHoraEntrega,
            String^ ruta,
            String^ prioridad,
            ConfiguracionSistema^ configuracion,
            Almacen^ almacenOrigen,
            List<Insumo^>^ insumos
        );
    };
}