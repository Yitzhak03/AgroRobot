#pragma once

namespace AgroRobotController {
    using namespace System;
    using namespace System::Collections::Generic;

    public ref class EstadisticaAlimentacionResult {
    public:
        property String^ Categoria;
        property int Cantidad;
        property double Porcentaje;

        EstadisticaAlimentacionResult(String^ categoria, int cantidad, double porcentaje);
    };

    public ref class DietaResumenResult {
    public:
        property int IdDieta;
        property int IdAnimal;
        property String^ Alimentos;
        property String^ Frecuencia;
        property String^ FechaInicio;
        property String^ Prioridad;

        DietaResumenResult(int idDieta, int idAnimal, String^ alimentos, String^ frecuencia, String^ fechaInicio, String^ prioridad);
    };

    public ref class ReporteAlimentacionResult {
    public:
        property String^ Periodo;
        property int TotalDietas;
        property int DietasActivas;
        property int DietasInactivas;
        property List<EstadisticaAlimentacionResult^>^ PorTipoDieta;
        property List<EstadisticaAlimentacionResult^>^ TopAlimentos;
        property List<DietaResumenResult^>^ DietasDetalladas;

        ReporteAlimentacionResult();
    };


    public ref class ReporteAlimentacionController {
    public:
        ReporteAlimentacionController();

        ReporteAlimentacionResult^ GenerarReporteMensual(int anio, int mes);
        ReporteAlimentacionResult^ GenerarReportePorRangoFechas(String^ fechaInicio, String^ fechaFin);
        ReporteAlimentacionResult^ GenerarReportePorPrioridad(String^ prioridad);

    private:
        String^ DeterminarTipoDieta(String^ alimentos);
        List<String^>^ ExtraerAlimentos(String^ alimentos);
        String^ DeterminarEstadoDieta(String^ fechaInicio);
    };
}