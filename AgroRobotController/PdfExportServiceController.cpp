#include "PdfExportServiceController.h"
#include "ReporteDataController.h"
#include "ReporteAlimentacionController.h"

using namespace AgroRobotController;
using namespace System::IO;
using namespace System::Text;

PdfExportServiceController::PdfExportServiceController() {
    // Constructor
}

bool PdfExportServiceController::ExportarReporteDiagnosticoPDF(ReporteDiagnosticoResult^ reporte, String^ filePath) {
    try {
        StreamWriter^ writer = gcnew StreamWriter(filePath, false, Encoding::UTF8);

        try {
            EscribirCabeceraPDF(writer, reporte);
            writer->WriteLine();
            EscribirEstadisticasPDF(writer, reporte);
            writer->WriteLine();
            EscribirDetalleMuestrasPDF(writer, reporte);

            writer->WriteLine();
            writer->WriteLine("=== FIN DEL REPORTE ===");
            writer->WriteLine("Generado el: " + DateTime::Now.ToString("dd/MM/yyyy HH:mm"));

            return true;
        }
        finally {
            writer->Close();
        }
    }
    catch (Exception^) {
        return false;
    }
}

bool PdfExportServiceController::ExportarReporteDiagnosticoExcel(ReporteDiagnosticoResult^ reporte, String^ filePath) {
    try {
        StreamWriter^ writer = gcnew StreamWriter(filePath, false, Encoding::UTF8);

        try {
            EscribirCabeceraExcel(writer, reporte);
            writer->WriteLine();
            EscribirEstadisticasExcel(writer, reporte);

            return true;
        }
        finally {
            writer->Close();
        }
    }
    catch (Exception^) {
        return false;
    }
}

// Implementaciones de los métodos privados (deben coincidir exactamente con la declaración)
void PdfExportServiceController::EscribirCabeceraPDF(StreamWriter^ writer, ReporteDiagnosticoResult^ reporte) {
    writer->WriteLine("================================================");
    writer->WriteLine("         REPORTE DE DIAGNÓSTICO MÉDICO");
    writer->WriteLine("================================================");
    writer->WriteLine("Período: " + reporte->Periodo);
    writer->WriteLine("Fecha de generación: " + DateTime::Now.ToString("dd/MM/yyyy"));
    writer->WriteLine();
    writer->WriteLine("RESUMEN EJECUTIVO");
    writer->WriteLine("Total de muestras: " + reporte->TotalMuestras);
    writer->WriteLine("Total de animales: " + reporte->TotalAnimales);
}

void PdfExportServiceController::EscribirEstadisticasPDF(StreamWriter^ writer, ReporteDiagnosticoResult^ reporte) {
    writer->WriteLine("ESTADÍSTICAS POR TIPO DE ANÁLISIS");
    writer->WriteLine("-----------------------------------");
    for each (EstadisticaReporte ^ stat in reporte->PorTipoAnalisis) {
        writer->WriteLine(String::Format("{0}: {1} muestras ({2:F1}%)",
            stat->Categoria, stat->Cantidad, stat->Porcentaje));
    }

    writer->WriteLine();
    writer->WriteLine("ESTADÍSTICAS POR ESTADO DE SALUD");
    writer->WriteLine("---------------------------------");
    for each (EstadisticaReporte ^ stat in reporte->PorEstadoSalud) {
        writer->WriteLine(String::Format("{0}: {1} muestras ({2:F1}%)",
            stat->Categoria, stat->Cantidad, stat->Porcentaje));
    }
}

void PdfExportServiceController::EscribirDetalleMuestrasPDF(StreamWriter^ writer, ReporteDiagnosticoResult^ reporte) {
    writer->WriteLine("DETALLE DE MUESTRAS");
    writer->WriteLine("-------------------");

    if (reporte->MuestrasResumen->Count == 0) {
        writer->WriteLine("No hay muestras para el período seleccionado.");
        return;
    }

    for (int i = 0; i < reporte->MuestrasResumen->Count; i++) {
        writer->WriteLine(String::Format("{0}. {1}", i + 1, reporte->MuestrasResumen[i]));

        if ((i + 1) % 5 == 0 && (i + 1) < reporte->MuestrasResumen->Count) {
            writer->WriteLine("---");
        }
    }
}

void PdfExportServiceController::EscribirCabeceraExcel(StreamWriter^ writer, ReporteDiagnosticoResult^ reporte) {
    writer->WriteLine("Reporte de Diagnóstico Médico");
    writer->WriteLine("Período:," + reporte->Periodo);
    writer->WriteLine("Fecha de generación:," + DateTime::Now.ToString("dd/MM/yyyy"));
    writer->WriteLine("Total de muestras:," + reporte->TotalMuestras);
    writer->WriteLine("Total de animales:," + reporte->TotalAnimales);
    writer->WriteLine();
}

void PdfExportServiceController::EscribirEstadisticasExcel(StreamWriter^ writer, ReporteDiagnosticoResult^ reporte) {
    writer->WriteLine("ESTADÍSTICAS POR TIPO DE ANÁLISIS");
    writer->WriteLine("Tipo,Cantidad,Porcentaje");
    for each (EstadisticaReporte ^ stat in reporte->PorTipoAnalisis) {
        writer->WriteLine(String::Format("{0},{1},{2:F1}",
            stat->Categoria, stat->Cantidad, stat->Porcentaje));
    }

    writer->WriteLine();

    writer->WriteLine("ESTADÍSTICAS POR ESTADO DE SALUD");
    writer->WriteLine("Estado,Cantidad,Porcentaje");
    for each (EstadisticaReporte ^ stat in reporte->PorEstadoSalud) {
        writer->WriteLine(String::Format("{0},{1},{2:F1}",
            stat->Categoria, stat->Cantidad, stat->Porcentaje));
    }

    writer->WriteLine();

    writer->WriteLine("DETALLE DE MUESTRAS");
    writer->WriteLine("Número,Detalle");
    for (int i = 0; i < reporte->MuestrasResumen->Count; i++) {
        writer->WriteLine(String::Format("{0},{1}", i + 1, reporte->MuestrasResumen[i]));
    }
}

bool PdfExportServiceController::ExportarReporteAlimentacionPDF(ReporteAlimentacionResult^ reporte, String^ filePath) {
    try {
        StreamWriter^ writer = gcnew StreamWriter(filePath, false, Encoding::UTF8);

        try {
            EscribirCabeceraAlimentacionPDF(writer, reporte);
            writer->WriteLine();
            EscribirEstadisticasAlimentacionPDF(writer, reporte);
            writer->WriteLine();
            EscribirDetalleDietasPDF(writer, reporte);

            writer->WriteLine();
            writer->WriteLine("=== FIN DEL REPORTE ===");
            writer->WriteLine("Generado el: " + DateTime::Now.ToString("dd/MM/yyyy HH:mm"));

            return true;
        }
        finally {
            writer->Close();
        }
    }
    catch (Exception^) {
        return false;
    }
}

bool PdfExportServiceController::ExportarReporteAlimentacionExcel(ReporteAlimentacionResult^ reporte, String^ filePath) {
    try {
        StreamWriter^ writer = gcnew StreamWriter(filePath, false, Encoding::UTF8);

        try {
            EscribirCabeceraAlimentacionExcel(writer, reporte);
            writer->WriteLine();
            EscribirEstadisticasAlimentacionExcel(writer, reporte);

            return true;
        }
        finally {
            writer->Close();
        }
    }
    catch (Exception^) {
        return false;
    }
}

void PdfExportServiceController::EscribirCabeceraAlimentacionPDF(StreamWriter^ writer, ReporteAlimentacionResult^ reporte) {
    writer->WriteLine("================================================");
    writer->WriteLine("         REPORTE DE PLAN DE ALIMENTACIÓN");
    writer->WriteLine("================================================");
    writer->WriteLine("Período: " + reporte->Periodo);
    writer->WriteLine("Fecha de generación: " + DateTime::Now.ToString("dd/MM/yyyy"));
    writer->WriteLine();
    writer->WriteLine("RESUMEN EJECUTIVO");
    writer->WriteLine("Total de dietas: " + reporte->TotalDietas);
    writer->WriteLine("Dietas activas: " + reporte->DietasActivas);
    writer->WriteLine("Dietas inactivas: " + reporte->DietasInactivas);
}

void PdfExportServiceController::EscribirEstadisticasAlimentacionPDF(StreamWriter^ writer, ReporteAlimentacionResult^ reporte) {
    writer->WriteLine("DISTRIBUCIÓN POR TIPO DE DIETA");
    writer->WriteLine("-----------------------------------");
    for each (EstadisticaAlimentacionResult ^ stat in reporte->PorTipoDieta) {
        writer->WriteLine(String::Format("{0}: {1} dietas ({2:F1}%)",
            stat->Categoria, stat->Cantidad, stat->Porcentaje));
    }

    writer->WriteLine();
    writer->WriteLine("TOP 5 ALIMENTOS MÁS UTILIZADOS");
    writer->WriteLine("---------------------------------");
    for each (EstadisticaAlimentacionResult ^ stat in reporte->TopAlimentos) {
        writer->WriteLine(String::Format("{0}: {1} usos ({2:F1}%)",
            stat->Categoria, stat->Cantidad, stat->Porcentaje));
    }
}

void PdfExportServiceController::EscribirDetalleDietasPDF(StreamWriter^ writer, ReporteAlimentacionResult^ reporte) {
    writer->WriteLine("DETALLE DE DIETAS");
    writer->WriteLine("-------------------");

    if (reporte->DietasDetalladas->Count == 0) {
        writer->WriteLine("No hay dietas para el período seleccionado.");
        return;
    }

    for (int i = 0; i < reporte->DietasDetalladas->Count; i++) {
        auto dieta = reporte->DietasDetalladas[i];
        writer->WriteLine(String::Format("{0}. Dieta #{1} - Animal #{2} - {3} - {4}",
            i + 1, dieta->IdDieta, dieta->IdAnimal, dieta->Alimentos, dieta->Prioridad));

        if ((i + 1) % 5 == 0 && (i + 1) < reporte->DietasDetalladas->Count) {
            writer->WriteLine("---");
        }
    }
}

void PdfExportServiceController::EscribirCabeceraAlimentacionExcel(StreamWriter^ writer, ReporteAlimentacionResult^ reporte) {
    writer->WriteLine("Reporte de Plan de Alimentación");
    writer->WriteLine("Período:," + reporte->Periodo);
    writer->WriteLine("Fecha de generación:," + DateTime::Now.ToString("dd/MM/yyyy"));
    writer->WriteLine("Total de dietas:," + reporte->TotalDietas);
    writer->WriteLine("Dietas activas:," + reporte->DietasActivas);
    writer->WriteLine("Dietas inactivas:," + reporte->DietasInactivas);
    writer->WriteLine();
}

void PdfExportServiceController::EscribirEstadisticasAlimentacionExcel(StreamWriter^ writer, ReporteAlimentacionResult^ reporte) {
    writer->WriteLine("DISTRIBUCIÓN POR TIPO DE DIETA");
    writer->WriteLine("Tipo Dieta,Cantidad,Porcentaje");
    for each (EstadisticaAlimentacionResult ^ stat in reporte->PorTipoDieta) {
        writer->WriteLine(String::Format("{0},{1},{2:F1}",
            stat->Categoria, stat->Cantidad, stat->Porcentaje));
    }

    writer->WriteLine();

    writer->WriteLine("TOP 5 ALIMENTOS MÁS UTILIZADOS");
    writer->WriteLine("Alimento,Cantidad Usos,Porcentaje");
    for each (EstadisticaAlimentacionResult ^ stat in reporte->TopAlimentos) {
        writer->WriteLine(String::Format("{0},{1},{2:F1}",
            stat->Categoria, stat->Cantidad, stat->Porcentaje));
    }

    writer->WriteLine();

    writer->WriteLine("DETALLE DE DIETAS");
    writer->WriteLine("ID Dieta,ID Animal,Alimentos,Frecuencia,Fecha Inicio,Prioridad");
    for each (DietaResumenResult ^ dieta in reporte->DietasDetalladas) {
        writer->WriteLine(String::Format("{0},{1},{2},{3},{4},{5}",
            dieta->IdDieta, dieta->IdAnimal, dieta->Alimentos,
            dieta->Frecuencia, dieta->FechaInicio, dieta->Prioridad));
    }
}