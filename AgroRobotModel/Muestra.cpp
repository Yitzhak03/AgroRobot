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
void Muestra::setIdMuestra(int idMuestra) { this->idMuestra = idMuestra; }

int Muestra::getIdAnimal() { return idAnimal; }
void Muestra::setIdAnimal(int idAnimal) { this->idAnimal = idAnimal; }

String^ Muestra::getTipo() { return tipo; }
void Muestra::setTipo(String^ t) { this->tipo = t; }

String^ Muestra::getFechaToma() { return fechaToma; }
void Muestra::setFechaToma(String^ fechaToma) { this->fechaToma = fechaToma; }

// Heces
String^ Muestra::getConsistencia() { return consistencia; }
void Muestra::setConsistencia(String^ consistencia) { this->consistencia = consistencia; }

String^ Muestra::getColorHeces() { return colorHeces; }
void Muestra::setColorHeces(String^ colorHeces) { this->colorHeces = colorHeces; }

String^ Muestra::getOlor() { return olor; }
void Muestra::setOlor(String^ olor) { this->olor = olor; }

String^ Muestra::getParasitos() { return parasitos; }
void Muestra::setParasitos(String^ parasitos) { this->parasitos = parasitos; }

// Sangre
String^ Muestra::getCantidadExtraida() { return cantidadExtraida; }
void Muestra::setCantidadExtraida(String^ cantidadExtraida) { this->cantidadExtraida = cantidadExtraida; }

String^ Muestra::getColorSangre() { return colorSangre; }
void Muestra::setColorSangre(String^ colorSangre) { this->colorSangre = colorSangre; }

String^ Muestra::getCoagulos() { return coagulos; }
void Muestra::setCoagulos(String^ coagulos) { this->coagulos = coagulos; }

String^ Muestra::getContaminacion() { return contaminacion; }
void Muestra::setContaminacion(String^ contaminacion) { this->contaminacion = contaminacion; }
