#pragma once

namespace AgroRobotModel {
    
    using namespace System;
    
    public ref class Diagnostico {
    private:
        
        int idDiagnostico;
        int idAnimal;
        String^ especie;
        String^ resultadoHeces;
        String^ resultadoSangre;
        String^ estadoSalud;
        String^ observaciones;
        String^ fecha;

    public:
        Diagnostico();
        Diagnostico(
            int idDiagnostico,
            int idAnimal,
            String^ especie,
            String^ resultadoHeces,
            String^ resultadoSangre,
            String^ estadoSalud,
            String^ observaciones,
            String^ fecha
        );

        // Getters
        int getIdDiagnostico();
        int getIdAnimal();
        String^ getEspecie();
        String^ getResultadoHeces();
        String^ getResultadoSangre();
        String^ getEstadoSalud();
        String^ getObservaciones();
        String^ getFecha();

        // Setters
        void setIdDiagnostico(int idDiagnostico);
        void setIdAnimal(int idAnimal);
        void setEspecie(String^ especie);
        void setResultadoHeces(String^ resultadoHeces);
        void setResultadoSangre(String^ resultadoSangre);
        void setEstadoSalud(String^ estado);
        void setObservaciones(String^ obs);
        void setFecha(String^ fecha);
    };
}