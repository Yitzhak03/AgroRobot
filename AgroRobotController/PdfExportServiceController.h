#pragma once

namespace AgroRobotController {
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::IO;

	// Declaraciones adelantadas (Forward declarations)
	ref class ReporteDiagnosticoResult;
	ref class EstadisticaReporte;
	ref class ReporteAlimentacionResult;
	ref class EstadisticaAlimentacionResult;
	ref class DietaResumenResult;

	public ref class PdfExportServiceController {
	public:
		// Constructor
		PdfExportServiceController();

		// --- MÉTODOS PÚBLICOS (DIAGNÓSTICO) ---
		// Corrección: Usamos System::String^ explícitamente
		bool ExportarReporteDiagnosticoPDF(ReporteDiagnosticoResult^ reporte, System::String^ filePath);
		bool ExportarReporteDiagnosticoExcel(ReporteDiagnosticoResult^ reporte, System::String^ filePath);

		// --- MÉTODOS PÚBLICOS (ALIMENTACIÓN) ---
		// Corrección: Usamos System::String^ explícitamente
		bool ExportarReporteAlimentacionPDF(ReporteAlimentacionResult^ reporte, System::String^ filePath);
		bool ExportarReporteAlimentacionExcel(ReporteAlimentacionResult^ reporte, System::String^ filePath);

	private:
		// --- MÉTODOS PRIVADOS AUXILIARES (DIAGNÓSTICO) ---
		void EscribirCabeceraPDF(StreamWriter^ writer, ReporteDiagnosticoResult^ reporte);
		void EscribirEstadisticasPDF(StreamWriter^ writer, ReporteDiagnosticoResult^ reporte);
		void EscribirDetalleMuestrasPDF(StreamWriter^ writer, ReporteDiagnosticoResult^ reporte);

		void EscribirCabeceraExcel(StreamWriter^ writer, ReporteDiagnosticoResult^ reporte);
		void EscribirEstadisticasExcel(StreamWriter^ writer, ReporteDiagnosticoResult^ reporte);

		// --- MÉTODOS PRIVADOS AUXILIARES (ALIMENTACIÓN) ---
		void EscribirCabeceraAlimentacionPDF(StreamWriter^ writer, ReporteAlimentacionResult^ reporte);
		void EscribirEstadisticasAlimentacionPDF(StreamWriter^ writer, ReporteAlimentacionResult^ reporte);
		void EscribirDetalleDietasPDF(StreamWriter^ writer, ReporteAlimentacionResult^ reporte);

		void EscribirCabeceraAlimentacionExcel(StreamWriter^ writer, ReporteAlimentacionResult^ reporte);
		void EscribirEstadisticasAlimentacionExcel(StreamWriter^ writer, ReporteAlimentacionResult^ reporte);
	};
}