#pragma once

namespace AgroRobotController {
    using namespace System;
    using namespace System::Collections::Generic;

    public ref class EstadisticaReporte {
    public:
        property String^ Categoria;
        property int Cantidad;
        property double Porcentaje;

        EstadisticaReporte(String^ categoria, int cantidad, double porcentaje);
    };

    public ref class ReporteDiagnosticoResult {
    public:
        property String^ Periodo;
        property int TotalMuestras;
        property int TotalAnimales;
        property List<EstadisticaReporte^>^ PorTipoAnalisis;
        property List<EstadisticaReporte^>^ PorEstadoSalud;
        property List<String^>^ MuestrasResumen;

        ReporteDiagnosticoResult();
    };
}