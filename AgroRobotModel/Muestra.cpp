#include "Muestra.h"

using namespace AgroRobotModel;

// Constructor por defecto
Muestra::Muestra() {
    idMuestra = 0;
    idAnimal = 0;
    tipo = "";
    fechaToma = "";

    // Heces
    consistencia = "";
    colorHeces = "";
    olor = "";
    parasitos = "";

    // Sangre
    cantidadExtraida = "";
    colorSangre = "";
    coagulos = "";
    contaminacion = "";
}

// Constructor parametrizado
Muestra::Muestra(int idMuestra, int idAnimal, String^ tipo, String^ fechaToma,
    String^ consistencia, String^ colorHeces, String^ olor, String^ parasitos,
    String^ cantidadExtraida, String^ colorSangre, String^ coagulos, String^ contaminacion) {
    this->idMuestra = idMuestra;
    this->idAnimal = idAnimal;
    this->tipo = tipo;
    this->fechaToma = fechaToma;

    this->consistencia = consistencia;
    this->colorHeces = colorHeces;
    this->olor = olor;
    this->parasitos = parasitos;

    this->cantidadExtraida = cantidadExtraida;
    this->colorSangre = colorSangre;
    this->coagulos = coagulos;
    this->contaminacion = contaminacion;
}

// Getters y setters
int Muestra::getIdMuestra() { return idMuestra; }
void Muestra::setIdMuestra(int id) { idMuestra = id; }

int Muestra::getIdAnimal() { return idAnimal; }
void Muestra::setIdAnimal(int id) { idAnimal = id; }

String^ Muestra::getTipo() { return tipo; }
void Muestra::setTipo(String^ t) { tipo = t; }

String^ Muestra::getFechaToma() { return fechaToma; }
void Muestra::setFechaToma(String^ f) { fechaToma = f; }

// Heces
String^ Muestra::getConsistencia() { return consistencia; }
void Muestra::setConsistencia(String^ v) { consistencia = v; }

String^ Muestra::getColorHeces() { return colorHeces; }
void Muestra::setColorHeces(String^ v) { colorHeces = v; }

String^ Muestra::getOlor() { return olor; }
void Muestra::setOlor(String^ v) { olor = v; }

String^ Muestra::getParasitos() { return parasitos; }
void Muestra::setParasitos(String^ v) { parasitos = v; }

// Sangre
String^ Muestra::getCantidadExtraida() { return cantidadExtraida; }
void Muestra::setCantidadExtraida(String^ v) { cantidadExtraida = v; }

String^ Muestra::getColorSangre() { return colorSangre; }
void Muestra::setColorSangre(String^ v) { colorSangre = v; }

String^ Muestra::getCoagulos() { return coagulos; }
void Muestra::setCoagulos(String^ v) { coagulos = v; }

String^ Muestra::getContaminacion() { return contaminacion; }
void Muestra::setContaminacion(String^ v) { contaminacion = v; }
