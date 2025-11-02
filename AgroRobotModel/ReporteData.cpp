#include "ReporteData.h"
#include "Muestra.h"  // Incluir Muestra.h

using namespace AgroRobotModel;

EstadisticaDiagnostico::EstadisticaDiagnostico() {
    categoria = "";
    cantidad = 0;
    porcentaje = 0.0;
}

EstadisticaDiagnostico::EstadisticaDiagnostico(String^ categoria, int cantidad, double porcentaje) {
    this->categoria = categoria;
    this->cantidad = cantidad;
    this->porcentaje = porcentaje;
}

ReporteDiagnosticoData::ReporteDiagnosticoData() {
    periodo = "";
    totalMuestras = 0;
    totalAnimales = 0;
    porTipoAnalisis = gcnew List<EstadisticaDiagnostico^>();
    porEstadoSalud = gcnew List<EstadisticaDiagnostico^>();
    muestrasDetalladas = gcnew List<Muestra^>();
}