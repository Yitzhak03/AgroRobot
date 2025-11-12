#include "Diagnostico.h"

namespace AgroRobotModel {

    // Constructor vacío
    Diagnostico::Diagnostico() {
        this->idDiagnostico = 0;
        this->idAnimal = 0;
        this->especie = "";
        this->resultadoHeces = "";
        this->resultadoSangre = "";
        this->estadoSalud = "";
        this->observaciones = "";
        this->fecha = "";
    }

    // Constructor con parámetros
    Diagnostico::Diagnostico(
        int idDiagnostico,
        int idAnimal,
        String^ especie,
        String^ resultadoHeces,
        String^ resultadoSangre,
        String^ estadoSalud,
        String^ observaciones,
        String^ fecha
    ) {
        this->idDiagnostico = idDiagnostico;
        this->idAnimal = idAnimal;
        this->especie = especie;
        this->resultadoHeces = resultadoHeces;
        this->resultadoSangre = resultadoSangre;
        this->estadoSalud = estadoSalud;
        this->observaciones = observaciones;
        this->fecha = fecha;
    }

    // Getters
    int Diagnostico::getIdDiagnostico() { return this->idDiagnostico; }
    int Diagnostico::getIdAnimal() { return this->idAnimal; }
    String^ Diagnostico::getEspecie() { return this->especie; }
    String^ Diagnostico::getResultadoHeces() { return this->resultadoHeces; }
    String^ Diagnostico::getResultadoSangre() { return this->resultadoSangre; }
    String^ Diagnostico::getEstadoSalud() { return this->estadoSalud; }
    String^ Diagnostico::getObservaciones() { return this->observaciones; }
    String^ Diagnostico::getFecha() { return this->fecha; }

    // Setters
    void Diagnostico::setIdDiagnostico(int idDiagnostico) { this->idDiagnostico = idDiagnostico; }
    void Diagnostico::setIdAnimal(int idAnimal) { this->idAnimal = idAnimal; }
    void Diagnostico::setEspecie(String^ especie) { this->especie = especie; }
    void Diagnostico::setResultadoHeces(String^ resultadoHeces) { this->resultadoHeces = resultadoHeces; }
    void Diagnostico::setResultadoSangre(String^ resultadoSangre) { this->resultadoSangre = resultadoSangre; }
    void Diagnostico::setEstadoSalud(String^ estado) { this->estadoSalud = estado; }
    void Diagnostico::setObservaciones(String^ obs) { this->observaciones = obs; }
    void Diagnostico::setFecha(String^ fecha) { this->fecha = fecha; }
}
