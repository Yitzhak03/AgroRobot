#pragma once

namespace AgroRobotController {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace System::IO;

    // Forward declaration de las estructuras de ReporteDataController
    ref class ReporteDiagnosticoResult;
    ref class EstadisticaReporte;

    ref class ReporteAlimentacionResult;
    ref class EstadisticaAlimentacionResult;
    ref class DietaResumenResult;

    public ref class PdfExportServiceController {
    public:
        PdfExportServiceController();

        static bool ExportarReporteDiagnosticoPDF(ReporteDiagnosticoResult^ reporte, String^ filePath);
        static bool ExportarReporteDiagnosticoExcel(ReporteDiagnosticoResult^ reporte, String^ filePath);
        static bool ExportarReporteAlimentacionPDF(ReporteAlimentacionResult^ reporte, String^ filePath);
        static bool ExportarReporteAlimentacionExcel(ReporteAlimentacionResult^ reporte, String^ filePath);


    private:
        static void EscribirCabeceraPDF(StreamWriter^ writer, ReporteDiagnosticoResult^ reporte);
        static void EscribirEstadisticasPDF(StreamWriter^ writer, ReporteDiagnosticoResult^ reporte);
        static void EscribirDetalleMuestrasPDF(StreamWriter^ writer, ReporteDiagnosticoResult^ reporte);

        static void EscribirCabeceraExcel(StreamWriter^ writer, ReporteDiagnosticoResult^ reporte);
        static void EscribirEstadisticasExcel(StreamWriter^ writer, ReporteDiagnosticoResult^ reporte);
        static void EscribirCabeceraAlimentacionPDF(StreamWriter^ writer, ReporteAlimentacionResult^ reporte);
        static void EscribirEstadisticasAlimentacionPDF(StreamWriter^ writer, ReporteAlimentacionResult^ reporte);
        static void EscribirDetalleDietasPDF(StreamWriter^ writer, ReporteAlimentacionResult^ reporte);

        static void EscribirCabeceraAlimentacionExcel(StreamWriter^ writer, ReporteAlimentacionResult^ reporte);
        static void EscribirEstadisticasAlimentacionExcel(StreamWriter^ writer, ReporteAlimentacionResult^ reporte);
    };
}