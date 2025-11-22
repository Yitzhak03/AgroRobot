#include "PdfExportServiceController.h"
#include "ReporteDataController.h" 
// Si tienes errores de inclusión, asegúrate de que ReporteDataController.h 
// contiene la definición de ReporteDiagnosticoResult

using namespace AgroRobotController;
using namespace System::IO;
using namespace System::Text;

PdfExportServiceController::PdfExportServiceController() {
	// Constructor vacío
}

// ================== EXPORTAR A EXCEL (CSV) ==================
bool PdfExportServiceController::ExportarReporteDiagnosticoExcel(ReporteDiagnosticoResult^ reporte, String^ filePath) {
	try {
		// UTF8 con BOM para tildes
		StreamWriter^ writer = gcnew StreamWriter(filePath, false, Encoding::UTF8);
		try {
			writer->WriteLine("sep=,"); // Truco para forzar columnas en Excel
			EscribirCabeceraExcel(writer, reporte);
			writer->WriteLine();
			EscribirEstadisticasExcel(writer, reporte);
			return true;
		}
		finally {
			writer->Close();
		}
	}
	catch (Exception^ ex) {
		
		return false;
	}
}

void PdfExportServiceController::EscribirCabeceraExcel(StreamWriter^ writer, ReporteDiagnosticoResult^ reporte) {
	writer->WriteLine("REPORTE DE DIAGNOSTICO MEDICO");
	writer->WriteLine("Periodo:," + reporte->Periodo);
	writer->WriteLine("Generado:," + DateTime::Now.ToString("dd/MM/yyyy"));
	writer->WriteLine("Total Muestras:," + reporte->TotalMuestras);
	writer->WriteLine("Total Animales:," + reporte->TotalAnimales);
}

void PdfExportServiceController::EscribirEstadisticasExcel(StreamWriter^ writer, ReporteDiagnosticoResult^ reporte) {
	writer->WriteLine("ESTADISTICAS POR TIPO");
	writer->WriteLine("Tipo,Cantidad,Porcentaje");
	for each (EstadisticaReporte ^ stat in reporte->PorTipoAnalisis) {
		writer->WriteLine(String::Format("{0},{1},{2:F2}%", stat->Categoria, stat->Cantidad, stat->Porcentaje));
	}
	writer->WriteLine();
	writer->WriteLine("ESTADISTICAS POR SALUD");
	writer->WriteLine("Estado,Cantidad,Porcentaje");
	for each (EstadisticaReporte ^ stat in reporte->PorEstadoSalud) {
		writer->WriteLine(String::Format("{0},{1},{2:F2}%", stat->Categoria, stat->Cantidad, stat->Porcentaje));
	}
	writer->WriteLine();
	writer->WriteLine("DETALLE");
	writer->WriteLine("N,Descripcion");
	for (int i = 0; i < reporte->MuestrasResumen->Count; i++) {
		// Reemplazar comas por puntos en el texto para no romper columnas
		String^ texto = reporte->MuestrasResumen[i]->Replace(",", ".");
		writer->WriteLine((i + 1) + "," + texto);
	}
}

// ================== EXPORTAR A TEXTO (SIMULANDO PDF) ==================
bool PdfExportServiceController::ExportarReporteDiagnosticoPDF(ReporteDiagnosticoResult^ reporte, String^ filePath) {
	try {
		StreamWriter^ writer = gcnew StreamWriter(filePath, false, Encoding::UTF8);
		try {
			EscribirCabeceraPDF(writer, reporte);
			writer->WriteLine("");
			EscribirEstadisticasPDF(writer, reporte);
			writer->WriteLine("");
			EscribirDetalleMuestrasPDF(writer, reporte);
			writer->WriteLine("================================================");
			return true;
		}
		finally {
			writer->Close();
		}
	}
	catch (Exception^ ex) {
		
		return false;
	}
}

void PdfExportServiceController::EscribirCabeceraPDF(StreamWriter^ writer, ReporteDiagnosticoResult^ reporte) {
	writer->WriteLine("================================================");
	writer->WriteLine("          REPORTE DE DIAGNOSTICO MEDICO         ");
	writer->WriteLine("================================================");
	writer->WriteLine("Periodo: " + reporte->Periodo);
	writer->WriteLine("Fecha:   " + DateTime::Now.ToString("dd/MM/yyyy"));
	writer->WriteLine("Muestras: " + reporte->TotalMuestras);
	writer->WriteLine("Animales: " + reporte->TotalAnimales);
}

void PdfExportServiceController::EscribirEstadisticasPDF(StreamWriter^ writer, ReporteDiagnosticoResult^ reporte) {
	writer->WriteLine("--- ESTADISTICAS ---");
	for each (EstadisticaReporte ^ stat in reporte->PorTipoAnalisis) {
		writer->WriteLine(String::Format("{0}: {1} ({2:F1}%)", stat->Categoria, stat->Cantidad, stat->Porcentaje));
	}
	writer->WriteLine();
	for each (EstadisticaReporte ^ stat in reporte->PorEstadoSalud) {
		writer->WriteLine(String::Format("{0}: {1} ({2:F1}%)", stat->Categoria, stat->Cantidad, stat->Porcentaje));
	}
}

void PdfExportServiceController::EscribirDetalleMuestrasPDF(StreamWriter^ writer, ReporteDiagnosticoResult^ reporte) {
	writer->WriteLine("--- DETALLE ---");
	for (int i = 0; i < reporte->MuestrasResumen->Count; i++) {
		writer->WriteLine((i + 1) + ". " + reporte->MuestrasResumen[i]);
	}
}

// Métodos Placeholder para Alimentación (Retornan false por ahora)
bool PdfExportServiceController::ExportarReporteAlimentacionPDF(ReporteAlimentacionResult^ r, String^ f) { return false; }
bool PdfExportServiceController::ExportarReporteAlimentacionExcel(ReporteAlimentacionResult^ r, String^ f) { return false; }