#pragma once

namespace AgroRobotModel {
    using namespace System;

    public ref class Diagnostico {
    public:
        // Atributos públicos
        int IdDiagnostico;
        int IdAnimal;
        String^ Especie;
        String^ ResultadoHeces;   // "Sí" o "No"
        String^ ResultadoSangre;  // "Sí" o "No"
        String^ EstadoSalud;
        String^ Observaciones;

        // Constructor vacío
        Diagnostico();

        // Constructor completo
        Diagnostico(
            int idDiagnostico,
            int idAnimal,
            String^ especie,
            String^ resultadoHeces,
            String^ resultadoSangre,
            String^ estadoSalud,
            String^ observaciones
        );
    };
}