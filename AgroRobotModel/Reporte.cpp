#include "Reporte.h"

using namespace AgroRobotModel;
using namespace System; // Necesario para DateTime

Reporte::Reporte() {
    // Inicialización del constructor por defecto
    this->idReporte = 0;
    this->tipo = "Sin Tipo";
    this->animalAlias = "N/A";
    this->fechaGeneracion = DateTime::Now;
    this->contenido = "Sin contenido";
    this->estadoSaludImpacto = "Óptimo"; // Valor inicial
    this->estadoGestion = "Pendiente"; // Valor inicial
}

// Implementación del constructor parametrizado
Reporte::Reporte(
    int idReporte,
    String^ tipo,
    String^ animalAlias,
    DateTime fechaGeneracion,
    String^ contenido,
    String^ estadoSaludImpacto,
    String^ estadoGestion)
{
    this->idReporte = idReporte;
    this->tipo = tipo;
    this->animalAlias = animalAlias;
    this->fechaGeneracion = fechaGeneracion;
    this->contenido = contenido;
    this->estadoSaludImpacto = estadoSaludImpacto;
    this->estadoGestion = estadoGestion;
}

// --- Getters ---

int Reporte::getIdReporte() {
    return this->idReporte;
}

String^ Reporte::getTipo() {
    return this->tipo;
}

String^ Reporte::getAnimalAlias() {
    return this->animalAlias;
}

DateTime Reporte::getFechaGeneracion() {
    return this->fechaGeneracion;
}

String^ Reporte::getContenido() {
    return this->contenido;
}

String^ Reporte::getEstadoSaludImpacto() {
    return this->estadoSaludImpacto;
}

String^ Reporte::getEstadoGestion() {
    return this->estadoGestion;
}

// --- Setters ---

void Reporte::setIdReporte(int idReporte) {
    this->idReporte = idReporte;
}

void Reporte::setTipo(String^ tipo) {
    this->tipo = tipo;
}

void Reporte::setAnimalAlias(String^ animalAlias) {
    this->animalAlias = animalAlias;
}

void Reporte::setFechaGeneracion(DateTime fechaGeneracion) {
    this->fechaGeneracion = fechaGeneracion;
}

void Reporte::setContenido(String^ contenido) {
    this->contenido = contenido;
}

void Reporte::setEstadoSaludImpacto(String^ estadoSaludImpacto) {
    this->estadoSaludImpacto = estadoSaludImpacto;
}

void Reporte::setEstadoGestion(String^ estadoGestion) {
    this->estadoGestion = estadoGestion;
}

// --- ToString() Override ---

String^ Reporte::ToString() {
    return String::Format("ID: {0}; Tipo: {1}; Animal: {2}; Fecha: {3}; Estado: {4}",
        this->idReporte,
        this->tipo,
        this->animalAlias,
        this->fechaGeneracion.ToString("dd/MM/yyyy"),
        this->estadoSaludImpacto);
}