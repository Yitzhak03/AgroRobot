#include "ReporteAlimentacion.h"

using namespace AgroRobotModel;

EstadisticaAlimentacion::EstadisticaAlimentacion() {
    categoria = "";
    cantidad = 0;
    porcentaje = 0.0;
}

EstadisticaAlimentacion::EstadisticaAlimentacion(String^ categoria, int cantidad, double porcentaje) {
    this->categoria = categoria;
    this->cantidad = cantidad;
    this->porcentaje = porcentaje;
}

DietaResumenData::DietaResumenData() {
    idDieta = 0;
    idAnimal = 0;
    alimentos = "";
    frecuencia = "";
    fechaInicio = "";
    prioridad = "";
}

DietaResumenData::DietaResumenData(int idDieta, int idAnimal, String^ alimentos, String^ frecuencia, String^ fechaInicio, String^ prioridad) {
    this->idDieta = idDieta;
    this->idAnimal = idAnimal;
    this->alimentos = alimentos;
    this->frecuencia = frecuencia;
    this->fechaInicio = fechaInicio;
    this->prioridad = prioridad;
}

ReporteAlimentacionData::ReporteAlimentacionData() {
    periodo = "";
    totalDietas = 0;
    dietasActivas = 0;
    dietasInactivas = 0;
    porTipoDieta = gcnew List<EstadisticaAlimentacion^>();
    topAlimentos = gcnew List<EstadisticaAlimentacion^>();
    dietasDetalladas = gcnew List<DietaResumenData^>();
}