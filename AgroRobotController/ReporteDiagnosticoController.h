#pragma once
#include "ReporteDataController.h"  // Solo otro Controller
#include "MuestraController.h"      // Controller existente
#include "GestorNutricionalController.h"  // Controller existente

namespace AgroRobotController {
    using namespace System;
    using namespace System::Collections::Generic;

    public ref class ReporteDiagnosticoController {
    public:
        ReporteDiagnosticoController();

        ReporteDiagnosticoResult^ GenerarReporteMensual(int anio, int mes);
        ReporteDiagnosticoResult^ GenerarReportePorRangoFechas(String^ fechaInicio, String^ fechaFin);
        bool ExportarReportePDF(ReporteDiagnosticoResult^ reporte, String^ filePath);
        bool ExportarReporteExcel(ReporteDiagnosticoResult^ reporte, String^ filePath);

    private:
        String^ ObtenerEstadoSalud(String^ tipo, String^ coagulos, String^ contaminacion,
            String^ parasitos, String^ consistencia, String^ olor);
    };
}