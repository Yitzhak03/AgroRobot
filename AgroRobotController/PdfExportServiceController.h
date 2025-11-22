#pragma once

namespace AgroRobotController {
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::IO;

	// Declaraciones adelantadas para que no se queje el compilador
	ref class ReporteDiagnosticoResult;
	ref class EstadisticaReporte;
	ref class ReporteAlimentacionResult;

	public ref class PdfExportServiceController {
	public:
		PdfExportServiceController(); // Constructor

		// Métodos Públicos (Sin static para usarlos con tu instancia actual)
		bool ExportarReporteDiagnosticoPDF(ReporteDiagnosticoResult^ reporte, String^ filePath);
		bool ExportarReporteDiagnosticoExcel(ReporteDiagnosticoResult^ reporte, String^ filePath);

		// Métodos vacíos para que no de error si los llamas desde otro lado
		bool ExportarReporteAlimentacionPDF(ReporteAlimentacionResult^ reporte, String^ filePath);
		bool ExportarReporteAlimentacionExcel(ReporteAlimentacionResult^ reporte, String^ filePath);

	private:
		// Métodos auxiliares
		void EscribirCabeceraPDF(StreamWriter^ writer, ReporteDiagnosticoResult^ reporte);
		void EscribirEstadisticasPDF(StreamWriter^ writer, ReporteDiagnosticoResult^ reporte);
		void EscribirDetalleMuestrasPDF(StreamWriter^ writer, ReporteDiagnosticoResult^ reporte);

		void EscribirCabeceraExcel(StreamWriter^ writer, ReporteDiagnosticoResult^ reporte);
		void EscribirEstadisticasExcel(StreamWriter^ writer, ReporteDiagnosticoResult^ reporte);
	};
}