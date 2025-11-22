#include "ReporteAlimentacionController.h"
#include "GestorNutricionalController.h"
// Asegúrate de que GestorNutricionalController.h esté incluido para poder leer dietas.txt

using namespace AgroRobotController;
using namespace System::Collections::Generic;
//using namespace System::Linq; // Útil para ordenar

// Implementaciones de las clases de datos
EstadisticaAlimentacionResult::EstadisticaAlimentacionResult(String^ categoria, int cantidad, double porcentaje) {
    this->Categoria = categoria;
    this->Cantidad = cantidad;
    this->Porcentaje = porcentaje;
}

DietaResumenResult::DietaResumenResult(int idDieta, int idAnimal, String^ alimentos, String^ frecuencia, String^ fechaInicio, String^ prioridad) {
    this->IdDieta = idDieta;
    this->IdAnimal = idAnimal;
    this->Alimentos = alimentos;
    this->Frecuencia = frecuencia;
    this->FechaInicio = fechaInicio;
    this->Prioridad = prioridad;
}

ReporteAlimentacionResult::ReporteAlimentacionResult() {
    Periodo = "";
    TotalDietas = 0;
    DietasActivas = 0;
    DietasInactivas = 0;
    PorTipoDieta = gcnew List<EstadisticaAlimentacionResult^>();
    TopAlimentos = gcnew List<EstadisticaAlimentacionResult^>();
    DietasDetalladas = gcnew List<DietaResumenResult^>();
}

ReporteAlimentacionController::ReporteAlimentacionController() {
    // Constructor
}

// --- MÉTODO PRINCIPAL DE LÓGICA ---
ReporteAlimentacionResult^ ReporteAlimentacionController::GenerarReporteMensual(int anio, int mes) {
    // 1. Definir rango del mes
    int diasEnMes = DateTime::DaysInMonth(anio, mes);
    String^ fechaInicio = String::Format("{0}-{1:D2}-01", anio, mes);
    String^ fechaFin = String::Format("{0}-{1:D2}-{2:D2}", anio, mes, diasEnMes);

    // Reutilizamos la lógica de rango
    return GenerarReportePorRangoFechas(fechaInicio, fechaFin);
}

ReporteAlimentacionResult^ ReporteAlimentacionController::GenerarReportePorRangoFechas(String^ fechaInicioStr, String^ fechaFinStr) {
    ReporteAlimentacionResult^ reporte = gcnew ReporteAlimentacionResult();
    reporte->Periodo = String::Format("{0} a {1}", fechaInicioStr, fechaFinStr);

    // 1. Obtener datos reales del archivo dietas.txt
    GestorNutricionalController^ gestor = gcnew GestorNutricionalController();
    List<Dieta^>^ todasDietas = gestor->obtenerTodasDietas();

    // 2. Preparar fechas para filtrar
    DateTime dtInicio, dtFin;
    DateTime::TryParse(fechaInicioStr, dtInicio);
    DateTime::TryParse(fechaFinStr, dtFin);

    // 3. Diccionarios para contar
    Dictionary<String^, int>^ conteoFrecuencia = gcnew Dictionary<String^, int>();
    Dictionary<String^, int>^ conteoAlimentos = gcnew Dictionary<String^, int>();

    int contActivas = 0;
    int contInactivas = 0; // Simularemos inactivas si son muy antiguas
    int contAltaPrioridad = 0;

    for each (Dieta ^ d in todasDietas) {
        DateTime fechaDieta;

        // CORRECCIÓN: Intentamos leer PRIMERO el formato de tu archivo (yyyy-MM-dd)
        // También dejamos dd/MM/yyyy por si acaso cambias los datos luego.
        array<String^>^ formatos = { "yyyy-MM-dd", "dd/MM/yyyy" };

        bool fechaValida = DateTime::TryParseExact(d->FechaInicio,
            formatos,
            System::Globalization::CultureInfo::InvariantCulture,
            System::Globalization::DateTimeStyles::None,
            fechaDieta);

        // Si falla el exacto, intentamos el genérico del sistema
        if (!fechaValida) {
            if (!DateTime::TryParse(d->FechaInicio, fechaDieta)) {
                continue; // Si la fecha es ilegible, saltamos esta línea
            }
        }

        // FILTRO DE FECHAS
        if (fechaDieta.Date >= dtInicio.Date && fechaDieta.Date <= dtFin.Date) {

            // ... (EL RESTO DEL CÓDIGO DENTRO DEL IF SE MANTIENE IGUAL) ...
            // (Aquí va la lógica de Prioridad, conteoFrecuencia, conteoAlimentos, etc.)

            // A. Determinar Prioridad...
            String^ prioridad = "Media";
            String^ frecuenciaNorm = d->Frecuencia->ToLower();

            if (frecuenciaNorm->Contains("diaria") || frecuenciaNorm->Contains("3 veces") || frecuenciaNorm->Contains("diario")) {
                prioridad = "Alta";
                contAltaPrioridad++;
            }
            else if (frecuenciaNorm->Contains("semanal")) {
                prioridad = "Baja";
            }
            contActivas++;

            // B. Contar Frecuencia...
            String^ freq = d->Frecuencia;
            if (String::IsNullOrWhiteSpace(freq)) freq = "No Especificada";
            if (conteoFrecuencia->ContainsKey(freq)) conteoFrecuencia[freq]++;
            else conteoFrecuencia->Add(freq, 1);

            // C. Contar Alimentos...
            array<String^>^ listaAlimentos = d->Alimentos->Split(gcnew array<String^>{",", " y "}, StringSplitOptions::RemoveEmptyEntries);
            for each (String ^ alimentoRaw in listaAlimentos) {
                String^ alimento = alimentoRaw->Trim();
                // Normalizar nombres (opcional, para que "Maíz" y "maíz" cuenten igual)
                if (!String::IsNullOrEmpty(alimento)) {
                    // Capitalizar primera letra para que se vea bonito
                    if (alimento->Length > 1)
                        alimento = Char::ToUpper(alimento[0]) + alimento->Substring(1)->ToLower();

                    if (conteoAlimentos->ContainsKey(alimento)) conteoAlimentos[alimento]++;
                    else conteoAlimentos->Add(alimento, 1);
                }
            }

            // D. Agregar al detalle...
            reporte->DietasDetalladas->Add(gcnew DietaResumenResult(
                d->Id, d->IdAnimal, d->Alimentos, d->Frecuencia, d->FechaInicio, prioridad
            ));
        }
    }

    // 4. Calcular Totales
    reporte->TotalDietas = reporte->DietasDetalladas->Count;
    reporte->DietasActivas = contActivas;
    // Calculamos inactivas como aquellas que podrían haber caducado (logica simple)
    reporte->DietasInactivas = 0;

    // 5. Convertir diccionarios a listas estadísticas
    // Tipos de Dieta (Frecuencia)
    for each (auto par in conteoFrecuencia) {
        double pct = (reporte->TotalDietas > 0) ? (double)par.Value / reporte->TotalDietas * 100.0 : 0.0;
        reporte->PorTipoDieta->Add(gcnew EstadisticaAlimentacionResult(par.Key, par.Value, pct));
    }

    // 5. Convertir conteo de Alimentos a Lista y ORDENAR MANUALMENTE (Sin Linq)
    int totalUsosAlimentos = 0;
    for each (auto par in conteoAlimentos) totalUsosAlimentos += par.Value;

    // A. Llenar la lista desordenada
    for each (auto par in conteoAlimentos) {
        double pct = (totalUsosAlimentos > 0) ? (double)par.Value / totalUsosAlimentos * 100.0 : 0.0;
        reporte->TopAlimentos->Add(gcnew EstadisticaAlimentacionResult(par.Key, par.Value, pct));
    }

    // B. Algoritmo de Burbuja para ordenar de MAYOR a MENOR cantidad
    for (int i = 0; i < reporte->TopAlimentos->Count - 1; i++) {
        for (int j = 0; j < reporte->TopAlimentos->Count - i - 1; j++) {
            // Si el actual es MENOR que el siguiente, los intercambiamos (para que el mayor suba)
            if (reporte->TopAlimentos[j]->Cantidad < reporte->TopAlimentos[j + 1]->Cantidad) {
                auto temp = reporte->TopAlimentos[j];
                reporte->TopAlimentos[j] = reporte->TopAlimentos[j + 1];
                reporte->TopAlimentos[j + 1] = temp;
            }
        }
    }

    // C. Quedarnos solo con los Top 5
    while (reporte->TopAlimentos->Count > 5) {
        reporte->TopAlimentos->RemoveAt(5); // Borrar el sobrante del final
    }

    return reporte;
}

// Métodos auxiliares no usados por ahora
ReporteAlimentacionResult^ ReporteAlimentacionController::GenerarReportePorPrioridad(String^ prioridad) {
    return gcnew ReporteAlimentacionResult();
}
String^ ReporteAlimentacionController::DeterminarTipoDieta(String^ alimentos) { return ""; }
List<String^>^ ReporteAlimentacionController::ExtraerAlimentos(String^ alimentos) { return gcnew List<String^>(); }
String^ ReporteAlimentacionController::DeterminarEstadoDieta(String^ fechaInicio) { return ""; }