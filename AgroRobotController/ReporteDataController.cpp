#include "ReporteDataController.h"

using namespace AgroRobotController;

EstadisticaReporte::EstadisticaReporte(String^ categoria, int cantidad, double porcentaje) {
    this->Categoria = categoria;
    this->Cantidad = cantidad;
    this->Porcentaje = porcentaje;
}

ReporteDiagnosticoResult::ReporteDiagnosticoResult() {
    Periodo = "";
    TotalMuestras = 0;
    TotalAnimales = 0;
    PorTipoAnalisis = gcnew List<EstadisticaReporte^>();
    PorEstadoSalud = gcnew List<EstadisticaReporte^>();
    MuestrasResumen = gcnew List<String^>();
}