#include "ReporteController.h"

using namespace AgroRobotController;
using namespace AgroRobotModel;
using namespace System::IO;

// Constructor: Carga los datos desde el archivo de texto
ReporteController::ReporteController() {
    this->listaReportes = gcnew List<Reporte^>();
    String^ path = "reportes.txt";

    if (!File::Exists(path)) {
        File::WriteAllText(path, ""); // Crea el archivo si no existe
    }

    array<String^>^ lineas = File::ReadAllLines(path);
    String^ separadores = ";";

    for each (String ^ linea in lineas) {
        if (String::IsNullOrWhiteSpace(linea)) continue;
        array<String^>^ campos = linea->Split(separadores->ToCharArray());

        // Debe haber 7 campos en total (ajustado a la nueva definición del modelo Reporte)
        if (campos->Length < 7) continue;

        int id = Convert::ToInt32(campos[0]);
        String^ tipo = campos[1];
        String^ animalAlias = campos[2];
        DateTime fecha;
        // La fecha se lee como String del archivo, la convertimos a DateTime
        DateTime::TryParse(campos[3], fecha);
        String^ contenido = campos[4];
        String^ estadoSaludImpacto = campos[5];
        String^ estadoGestion = campos[6];

        Reporte^ reporte = gcnew Reporte(
            id, tipo, animalAlias, fecha, contenido, estadoSaludImpacto, estadoGestion
        );
        this->listaReportes->Add(reporte);
    }
}

// Persistencia: Escribe toda la lista actual al archivo de texto
void ReporteController::escribirArchivo() {
    String^ path = "reportes.txt";
    array<String^>^ lineasArchivo = gcnew array<String^>(this->listaReportes->Count);

    for (int i = 0; i < this->listaReportes->Count; i++) {
        Reporte^ r = this->listaReportes[i];

        // Formato de guardado: ID;Tipo;AnimalAlias;Fecha(dd/MM/yyyy);Contenido;EstadoSaludImpacto;EstadoGestion
        String^ fechaString = r->getFechaGeneracion().ToString("dd/MM/yyyy");

        lineasArchivo[i] = String::Format("{0};{1};{2};{3};{4};{5};{6}",
            r->getIdReporte(),
            r->getTipo(),
            r->getAnimalAlias(),
            fechaString,
            r->getContenido(),
            r->getEstadoSaludImpacto(),
            r->getEstadoGestion()
        );
    }
    File::WriteAllLines(path, lineasArchivo);
}

// *** Método clave para el botón "Buscar" (button1_Click) ***
List<Reporte^>^ ReporteController::ConsultarReportesPorFiltros(
    String^ animalAlias,
    DateTime fechaInicio,
    DateTime fechaFin,
    String^ tipoAnalisis,
    String^ estadoSalud)
{
    List<Reporte^>^ resultados = gcnew List<Reporte^>();

    for each (Reporte ^ r in this->listaReportes) {
        // Criterio 1: ID Animal
        // String::IsNullOrEmpty(animalAlias) = no se aplicó el filtro O r->getAnimalAlias() es 'N/A'
        bool coincideAnimal = (String::IsNullOrWhiteSpace(animalAlias) ||
            r->getAnimalAlias()->Equals(animalAlias, StringComparison::OrdinalIgnoreCase));

        // Criterio 2: Rango de Fechas
        // La fechaFin debe incluir el final del día (ajustada en la vista)
        bool coincideFecha = r->getFechaGeneracion() >= fechaInicio &&
            r->getFechaGeneracion() <= fechaFin;

        // Criterio 3: Tipo de Análisis/Reporte (ej. "Salud", "Inventario")
        bool coincideTipoAnalisis = (String::IsNullOrWhiteSpace(tipoAnalisis) ||
            r->getTipo()->Equals(tipoAnalisis, StringComparison::OrdinalIgnoreCase));

        // Criterio 4: Estado de Salud (ej. "Crítico", "Óptimo")
        bool coincideEstadoSalud = (String::IsNullOrWhiteSpace(estadoSalud) ||
            r->getEstadoSaludImpacto()->Equals(estadoSalud, StringComparison::OrdinalIgnoreCase));

        if (coincideAnimal && coincideFecha && coincideTipoAnalisis && coincideEstadoSalud) {
            resultados->Add(r);
        }
    }

    return resultados;
}

// --- Métodos CRUD Adicionales ---

List<Reporte^>^ ReporteController::ObtenerTodosReportes() {
    return this->listaReportes;
}

void ReporteController::AgregarReporte(Reporte^ reporte) {
    // Lógica para asignar un nuevo ID antes de agregarlo
    this->listaReportes->Add(reporte);
    escribirArchivo();
}

Reporte^ ReporteController::ConsultarReportePorId(int id) {
    for each (Reporte ^ r in this->listaReportes) {
        if (r->getIdReporte() == id) {
            return r;
        }
    }
    return nullptr;
}

bool ReporteController::ModificarReporte(Reporte^ reporte) {
    for (int i = 0; i < this->listaReportes->Count; ++i) {
        if (this->listaReportes[i]->getIdReporte() == reporte->getIdReporte()) {
            this->listaReportes[i] = reporte;
            escribirArchivo();
            return true;
        }
    }
    return false;
}

bool ReporteController::EliminarReporte(int id) {
    Reporte^ r = ConsultarReportePorId(id);
    if (r != nullptr) {
        this->listaReportes->Remove(r);
        escribirArchivo();
        return true;
    }
    return false;
}

void ReporteController::CloseReporte() {
    this->listaReportes = nullptr;
}