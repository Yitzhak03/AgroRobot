#include "PdfExportServiceController.h"
// 1. INCLUSIONES CRÍTICAS:
// Necesitamos incluir los headers donde se definen las estructuras de los datos
// para que el compilador sepa qué es "PorTipoDieta", "TopAlimentos", etc.
#include "ReporteDataController.h"        // Para ReporteDiagnosticoResult
#include "ReporteAlimentacionController.h" // Para ReporteAlimentacionResult

// 2. NAMESPACES NECESARIOS:
using namespace AgroRobotController;
using namespace System::IO;
using namespace System::Text;
using namespace System;

PdfExportServiceController::PdfExportServiceController() {
	// Constructor vacío
}

// ================================================================
// EXPORTACIÓN DIAGNÓSTICO (EXCEL)
// ================================================================
bool PdfExportServiceController::ExportarReporteDiagnosticoExcel(ReporteDiagnosticoResult^ reporte, System::String^ filePath) {
	try {
		StreamWriter^ writer = gcnew StreamWriter(filePath, false, Encoding::UTF8);
		try {
			writer->WriteLine("sep=,");
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
		String^ texto = reporte->MuestrasResumen[i]->Replace(",", ".");
		writer->WriteLine((i + 1) + "," + texto);
	}
}

// ================================================================
// EXPORTACIÓN DIAGNÓSTICO (TXT/PDF)
// ================================================================
bool PdfExportServiceController::ExportarReporteDiagnosticoPDF(ReporteDiagnosticoResult^ reporte, System::String^ filePath) {
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

// ================================================================
// EXPORTACIÓN ALIMENTACIÓN (EXCEL)
// ================================================================
bool PdfExportServiceController::ExportarReporteAlimentacionExcel(ReporteAlimentacionResult^ reporte, System::String^ filePath) {
	try {
		StreamWriter^ writer = gcnew StreamWriter(filePath, false, Encoding::UTF8);
		try {
			writer->WriteLine("sep=,");
			EscribirCabeceraAlimentacionExcel(writer, reporte);
			writer->WriteLine();
			EscribirEstadisticasAlimentacionExcel(writer, reporte);
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

void PdfExportServiceController::EscribirCabeceraAlimentacionExcel(StreamWriter^ writer, ReporteAlimentacionResult^ reporte) {
	writer->WriteLine("REPORTE DE PLAN ALIMENTICIO");
	writer->WriteLine("Periodo:," + reporte->Periodo);
	writer->WriteLine("Generado:," + DateTime::Now.ToString("dd/MM/yyyy"));
	writer->WriteLine("Total Dietas:," + reporte->TotalDietas);
	writer->WriteLine("Dietas Activas:," + reporte->DietasActivas);
}

void PdfExportServiceController::EscribirEstadisticasAlimentacionExcel(StreamWriter^ writer, ReporteAlimentacionResult^ reporte) {
	writer->WriteLine("DISTRIBUCION POR FRECUENCIA");
	writer->WriteLine("Tipo,Cantidad,Porcentaje");
	for each (auto stat in reporte->PorTipoDieta) {
		writer->WriteLine(String::Format("{0},{1},{2:F2}%", stat->Categoria, stat->Cantidad, stat->Porcentaje));
	}

	writer->WriteLine();
	writer->WriteLine("TOP ALIMENTOS USADOS");
	writer->WriteLine("Alimento,Usos,Porcentaje");
	for each (auto stat in reporte->TopAlimentos) {
		writer->WriteLine(String::Format("{0},{1},{2:F2}%", stat->Categoria, stat->Cantidad, stat->Porcentaje));
	}

	writer->WriteLine();
	writer->WriteLine("DETALLE DE DIETAS");
	writer->WriteLine("ID Animal,Frecuencia,Prioridad,Alimentos");
	for each (auto dieta in reporte->DietasDetalladas) {
		String^ alimentosLimpio = dieta->Alimentos->Replace(",", " -");
		writer->WriteLine(String::Format("{0},{1},{2},{3}",
			dieta->IdAnimal, dieta->Frecuencia, dieta->Prioridad, alimentosLimpio));
	}
}

// ================================================================
// EXPORTACIÓN ALIMENTACIÓN (TXT/PDF)
// ================================================================
bool PdfExportServiceController::ExportarReporteAlimentacionPDF(ReporteAlimentacionResult^ reporte, System::String^ filePath) {
	try {
		StreamWriter^ writer = gcnew StreamWriter(filePath, false, Encoding::UTF8);
		try {
			EscribirCabeceraAlimentacionPDF(writer, reporte);
			writer->WriteLine("");
			EscribirEstadisticasAlimentacionPDF(writer, reporte);
			writer->WriteLine("");
			EscribirDetalleDietasPDF(writer, reporte);
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

void PdfExportServiceController::EscribirCabeceraAlimentacionPDF(StreamWriter^ writer, ReporteAlimentacionResult^ reporte) {
	writer->WriteLine("================================================");
	writer->WriteLine("          REPORTE DE PLAN ALIMENTICIO           ");
	writer->WriteLine("================================================");
	writer->WriteLine("Periodo: " + reporte->Periodo);
	writer->WriteLine("Fecha:   " + DateTime::Now.ToString("dd/MM/yyyy"));
	writer->WriteLine("Total Dietas:   " + reporte->TotalDietas);
	writer->WriteLine("Dietas Activas: " + reporte->DietasActivas);
}

void PdfExportServiceController::EscribirEstadisticasAlimentacionPDF(StreamWriter^ writer, ReporteAlimentacionResult^ reporte) {
	writer->WriteLine("--- ESTADISTICAS DE FRECUENCIA ---");
	for each (auto stat in reporte->PorTipoDieta) {
		writer->WriteLine(String::Format("{0,-15}: {1} ({2:F1}%)", stat->Categoria, stat->Cantidad, stat->Porcentaje));
	}
	writer->WriteLine();
	writer->WriteLine("--- TOP ALIMENTOS ---");
	for each (auto stat in reporte->TopAlimentos) {
		writer->WriteLine(String::Format("{0,-15}: {1} ({2:F1}%)", stat->Categoria, stat->Cantidad, stat->Porcentaje));
	}
}

void PdfExportServiceController::EscribirDetalleDietasPDF(StreamWriter^ writer, ReporteAlimentacionResult^ reporte) {
	writer->WriteLine("--- DETALLE DE DIETAS ---");
	for each (auto dieta in reporte->DietasDetalladas) {
		writer->WriteLine(String::Format("Animal #{0} | {1} | {2}", dieta->IdAnimal, dieta->Prioridad, dieta->Frecuencia));
		writer->WriteLine("   -> " + dieta->Alimentos);
		writer->WriteLine("-");
	}
}