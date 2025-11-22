#include "ReporteDiagnosticoController.h"
#include "MuestraController.h"
#include "GestorNutricionalController.h"

using namespace AgroRobotController;
using namespace System::Globalization;
using namespace System::IO;

ReporteDiagnosticoController::ReporteDiagnosticoController() {
    // Constructor
}

ReporteDiagnosticoResult^ ReporteDiagnosticoController::GenerarReporteMensual(int anio, int mes) {
    ReporteDiagnosticoResult^ reporte = gcnew ReporteDiagnosticoResult();
    reporte->Periodo = String::Format("{0}/{1:D2}", anio, mes);

    // Usar MuestraController para obtener datos
    MuestraController^ muestraController = gcnew MuestraController();
    GestorNutricionalController^ gestor = gcnew GestorNutricionalController();
    auto todasMuestras = muestraController->buscarTodasMuestrasArchivo(gestor);

    // Procesar datos
    Dictionary<String^, int>^ conteoTipos = gcnew Dictionary<String^, int>();
    Dictionary<String^, int>^ conteoEstados = gcnew Dictionary<String^, int>();
    Dictionary<int, bool>^ animalesUnicos = gcnew Dictionary<int, bool>();

    for (int i = 0; i < todasMuestras->Count; i++) {
        auto muestra = todasMuestras[i];

        // Verificar si es del mes
        String^ fecha = muestra->getFechaToma();
        try {
            DateTime fechaMuestra = DateTime::Parse(fecha);
            if (fechaMuestra.Year == anio && fechaMuestra.Month == mes) {

                // Contar por tipo
                String^ tipo = muestra->getTipo();
                if (conteoTipos->ContainsKey(tipo)) {
                    conteoTipos[tipo]++;
                }
                else {
                    conteoTipos->Add(tipo, 1);
                }

                // Determinar estado de salud
                String^ estado = ObtenerEstadoSalud(
                    muestra->getTipo(),
                    muestra->getCoagulos(),
                    muestra->getContaminacion(),
                    muestra->getParasitos(),
                    muestra->getConsistencia(),
                    muestra->getOlor()
                );

                if (conteoEstados->ContainsKey(estado)) {
                    conteoEstados[estado]++;
                }
                else {
                    conteoEstados->Add(estado, 1);
                }

                // Contar animales únicos
                int idAnimal = muestra->getIdAnimal();
                if (!animalesUnicos->ContainsKey(idAnimal)) {
                    animalesUnicos->Add(idAnimal, true);
                }

                // Agregar resumen para PDF
                reporte->MuestrasResumen->Add(
                    String::Format("Muestra #{0} - Animal #{1} - {2} - {3}",
                        muestra->getIdMuestra(), muestra->getIdAnimal(), tipo, fecha)
                );
            }
        }
        catch (Exception^) {
            // Si hay error en fecha, saltar esta muestra
            continue;
        }
    }

    // Calcular totales
    reporte->TotalMuestras = reporte->MuestrasResumen->Count;
    reporte->TotalAnimales = animalesUnicos->Count;

    // Calcular estadísticas
    for each (auto par in conteoTipos) {
        double porcentaje = (reporte->TotalMuestras > 0) ?
            (double)par.Value / reporte->TotalMuestras * 100.0 : 0.0;
        reporte->PorTipoAnalisis->Add(gcnew EstadisticaReporte(par.Key, par.Value, porcentaje));
    }

    for each (auto par in conteoEstados) {
        double porcentaje = (reporte->TotalMuestras > 0) ?
            (double)par.Value / reporte->TotalMuestras * 100.0 : 0.0;
        reporte->PorEstadoSalud->Add(gcnew EstadisticaReporte(par.Key, par.Value, porcentaje));
    }

    delete muestraController;
    return reporte;
}

String^ ReporteDiagnosticoController::ObtenerEstadoSalud(String^ tipo, String^ coagulos, String^ contaminacion,
    String^ parasitos, String^ consistencia, String^ olor) {

    // Limpieza
    if (tipo != nullptr) tipo = tipo->Trim()->ToLower();
    if (coagulos != nullptr) coagulos = coagulos->Trim()->ToLower();
    if (contaminacion != nullptr) contaminacion = contaminacion->Trim()->ToLower();
    if (parasitos != nullptr) parasitos = parasitos->Trim()->ToLower();
    if (consistencia != nullptr) consistencia = consistencia->Trim()->ToLower();
    if (olor != nullptr) olor = olor->Trim()->ToLower();

    // --- LÓGICA PARA SANGRE ---
    if (tipo == "sangre") {
        // Aceptamos "presente", "si" o "sí" (con tilde)
        bool tieneCoagulos = (coagulos == "presente" || coagulos == "si" || coagulos == "sí");

        // Aceptamos "alta" o "si" (dependiendo de cómo definas contaminación en tus datos)
        // En tus datos veo "No" y "Sí" en las columnas finales, asumo que aplica igual
        bool altaContaminacion = (contaminacion == "alta" || contaminacion == "si" || contaminacion == "sí");
        bool bajaContaminacion = (contaminacion == "baja" || contaminacion == "no");

        if (tieneCoagulos || altaContaminacion) {
            return "Crítico";
        }
        else if (!tieneCoagulos && bajaContaminacion) {
            return "Excelente";
        }
        return "Regular";
    }
    // --- LÓGICA PARA HECES ---
    else if (tipo == "heces") {
        // Aceptamos "presente", "si" o "sí"
        bool tieneParasitos = (parasitos == "presente" || parasitos == "si" || parasitos == "sí");

        // Consistencia "normal" o "sólida" (ajusta según tu criterio médico)
        bool esNormalConsistencia = (consistencia == "normal" || consistencia == "sólida" || consistencia == "solida");
        bool esNormalOlor = (olor == "normal");

        if (tieneParasitos) {
            return "Crítico";
        }
        else if (esNormalConsistencia && esNormalOlor) {
            return "Excelente";
        }
        return "Regular";
    }

    return "Desconocido";
}

ReporteDiagnosticoResult^ ReporteDiagnosticoController::GenerarReportePorRangoFechas(String^ fechaInicioStr, String^ fechaFinStr) {
    ReporteDiagnosticoResult^ reporte = gcnew ReporteDiagnosticoResult();
    reporte->Periodo = String::Format("{0} a {1}", fechaInicioStr, fechaFinStr);

    MuestraController^ muestraController = gcnew MuestraController();
    GestorNutricionalController^ gestor = gcnew GestorNutricionalController();
    auto todasMuestras = muestraController->buscarTodasMuestrasArchivo(gestor);

    // 1. Convertir los límites de búsqueda a DateTime real
    DateTime dtInicio;
    DateTime dtFin;
    // Asumimos formato yyyy-MM-dd porque viene del DateTimePicker convertido a String en el Form
    // O si lo enviaste como dd/MM/yyyy, ajusta aquí.
    // Lo más seguro es intentar parsear genérico:
    DateTime::TryParse(fechaInicioStr, dtInicio);
    DateTime::TryParse(fechaFinStr, dtFin);

    // Diccionarios para contar
    Dictionary<String^, int>^ conteoTipos = gcnew Dictionary<String^, int>();
    Dictionary<String^, int>^ conteoEstados = gcnew Dictionary<String^, int>();
    Dictionary<int, bool>^ animalesUnicos = gcnew Dictionary<int, bool>();

    for (int i = 0; i < todasMuestras->Count; i++) {
        auto muestra = todasMuestras[i];
        String^ fechaTexto = muestra->getFechaToma(); // Esto viene como "28/10/2025" del txt

        // 2. Convertir la fecha del TXT a DateTime
        DateTime fechaMuestra;
        bool esFechaValida = DateTime::TryParseExact(fechaTexto, "dd/MM/yyyy",
            System::Globalization::CultureInfo::InvariantCulture,
            System::Globalization::DateTimeStyles::None,
            fechaMuestra);

        if (esFechaValida) {
            // 3. COMPARACIÓN REAL DE FECHAS (No de texto)
            // Usamos Date para ignorar la hora (00:00:00)
            if (fechaMuestra.Date >= dtInicio.Date && fechaMuestra.Date <= dtFin.Date) {

                // --- LÓGICA DE CONTEO (Igual que tenías) ---
                String^ tipo = muestra->getTipo();
                if (conteoTipos->ContainsKey(tipo)) conteoTipos[tipo]++;
                else conteoTipos->Add(tipo, 1);

                String^ estado = ObtenerEstadoSalud(
                    muestra->getTipo(),
                    muestra->getCoagulos(),
                    muestra->getContaminacion(),
                    muestra->getParasitos(),
                    muestra->getConsistencia(),
                    muestra->getOlor()
                );

                if (conteoEstados->ContainsKey(estado)) conteoEstados[estado]++;
                else conteoEstados->Add(estado, 1);

                int idAnimal = muestra->getIdAnimal();
                if (!animalesUnicos->ContainsKey(idAnimal)) animalesUnicos->Add(idAnimal, true);

                reporte->MuestrasResumen->Add(
                    String::Format("Muestra #{0} - Animal #{1} - {2} - {3}",
                        muestra->getIdMuestra(), muestra->getIdAnimal(), tipo, fechaTexto)
                );
            }
        }
    }

    // Cálculos finales
    reporte->TotalMuestras = reporte->MuestrasResumen->Count;
    reporte->TotalAnimales = animalesUnicos->Count;

    for each(auto par in conteoTipos) {
        double porcentaje = (reporte->TotalMuestras > 0) ? (double)par.Value / reporte->TotalMuestras * 100.0 : 0.0;
        reporte->PorTipoAnalisis->Add(gcnew EstadisticaReporte(par.Key, par.Value, porcentaje));
    }

    for each(auto par in conteoEstados) {
        double porcentaje = (reporte->TotalMuestras > 0) ? (double)par.Value / reporte->TotalMuestras * 100.0 : 0.0;
        reporte->PorEstadoSalud->Add(gcnew EstadisticaReporte(par.Key, par.Value, porcentaje));
    }

    delete muestraController;
    return reporte;
}

bool ReporteDiagnosticoController::ExportarReportePDF(ReporteDiagnosticoResult^ reporte, String^ filePath) {
    try {
        StreamWriter^ writer = gcnew StreamWriter(filePath);

        writer->WriteLine("================================================");
        writer->WriteLine("         REPORTE DE DIAGNÓSTICO MÉDICO");
        writer->WriteLine("================================================");
        writer->WriteLine("Período: " + reporte->Periodo);
        writer->WriteLine("Fecha de generación: " + DateTime::Now.ToString("dd/MM/yyyy"));
        writer->WriteLine();
        writer->WriteLine("RESUMEN EJECUTIVO");
        writer->WriteLine("Total de muestras: " + reporte->TotalMuestras);
        writer->WriteLine("Total de animales: " + reporte->TotalAnimales);
        writer->WriteLine();

        writer->WriteLine("ESTADÍSTICAS POR TIPO DE ANÁLISIS");
        writer->WriteLine("-----------------------------------");
        for each (auto stat in reporte->PorTipoAnalisis) {
            writer->WriteLine(String::Format("{0}: {1} muestras ({2:F1}%)",
                stat->Categoria, stat->Cantidad, stat->Porcentaje));
        }

        writer->WriteLine();
        writer->WriteLine("ESTADÍSTICAS POR ESTADO DE SALUD");
        writer->WriteLine("---------------------------------");
        for each (auto stat in reporte->PorEstadoSalud) {
            writer->WriteLine(String::Format("{0}: {1} muestras ({2:F1}%)",
                stat->Categoria, stat->Cantidad, stat->Porcentaje));
        }

        writer->WriteLine();
        writer->WriteLine("DETALLE DE MUESTRAS");
        writer->WriteLine("-------------------");
        for (int i = 0; i < reporte->MuestrasResumen->Count; i++) {
            writer->WriteLine(String::Format("{0}. {1}", i + 1, reporte->MuestrasResumen[i]));
        }

        writer->WriteLine();
        writer->WriteLine("=== FIN DEL REPORTE ===");
        writer->WriteLine("Generado el: " + DateTime::Now.ToString("dd/MM/yyyy HH:mm"));

        writer->Close();
        return true;
    }
    catch (Exception^) {
        return false;
    }
}

bool ReporteDiagnosticoController::ExportarReporteExcel(ReporteDiagnosticoResult^ reporte, String^ filePath) {
    try {
        // Implementación básica de CSV (similar a Excel)
        StreamWriter^ writer = gcnew StreamWriter(filePath);

        writer->WriteLine("Periodo,Total Muestras,Total Animales");
        writer->WriteLine(String::Format("{0},{1},{2}",
            reporte->Periodo, reporte->TotalMuestras, reporte->TotalAnimales));

        writer->WriteLine();
        writer->WriteLine("Tipo Analisis,Cantidad,Porcentaje");
        for each (auto stat in reporte->PorTipoAnalisis) {
            writer->WriteLine(String::Format("{0},{1},{2:F1}",
                stat->Categoria, stat->Cantidad, stat->Porcentaje));
        }

        writer->WriteLine();
        writer->WriteLine("Estado Salud,Cantidad,Porcentaje");
        for each (auto stat in reporte->PorEstadoSalud) {
            writer->WriteLine(String::Format("{0},{1},{2:F1}",
                stat->Categoria, stat->Cantidad, stat->Porcentaje));
        }

        writer->Close();
        return true;
    }
    catch (Exception^) {
        return false;
    }
}