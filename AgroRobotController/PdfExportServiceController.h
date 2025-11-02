#pragma once

namespace AgroRobotController {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace System::IO;

    // Forward declaration de las estructuras de ReporteDataController
    ref class ReporteDiagnosticoResult;
    ref class EstadisticaReporte;

    public ref class PdfExportServiceController {
    public:
        PdfExportServiceController();

        static bool ExportarReporteDiagnosticoPDF(ReporteDiagnosticoResult^ reporte, String^ filePath);
        static bool ExportarReporteDiagnosticoExcel(ReporteDiagnosticoResult^ reporte, String^ filePath);

    private:
        static void EscribirCabeceraPDF(StreamWriter^ writer, ReporteDiagnosticoResult^ reporte);
        static void EscribirEstadisticasPDF(StreamWriter^ writer, ReporteDiagnosticoResult^ reporte);
        static void EscribirDetalleMuestrasPDF(StreamWriter^ writer, ReporteDiagnosticoResult^ reporte);

        static void EscribirCabeceraExcel(StreamWriter^ writer, ReporteDiagnosticoResult^ reporte);
        static void EscribirEstadisticasExcel(StreamWriter^ writer, ReporteDiagnosticoResult^ reporte);
    };
}