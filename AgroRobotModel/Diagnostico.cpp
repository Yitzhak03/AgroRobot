#include "Diagnostico.h"

using namespace AgroRobotModel;

Diagnostico::Diagnostico() {}

Diagnostico::Diagnostico(
    int idDiagnostico,
    int idAnimal,
    String^ especie,
    String^ resultadoHeces,
    String^ resultadoSangre,
    String^ estadoSalud,
    String^ observaciones
) {
    this->IdDiagnostico = idDiagnostico;
    this->IdAnimal = idAnimal;
    this->Especie = especie;
    this->ResultadoHeces = resultadoHeces;
    this->ResultadoSangre = resultadoSangre;
    this->EstadoSalud = estadoSalud;
    this->Observaciones = observaciones;
}
