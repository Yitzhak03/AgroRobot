#pragma once

namespace AgroRobotModel {

    using namespace System;

    public ref class Muestra {
    private:
        // Comunes
        int idMuestra;
        int idAnimal;
        String^ tipo; // "Heces" o "Sangre"
        String^ fechaToma;

        // Datos de heces
        String^ consistencia;
        String^ colorHeces;
        String^ olor;
        String^ parasitos;

        // Datos de sangre
        String^ cantidadExtraida;
        String^ colorSangre;
        String^ coagulos;
        String^ contaminacion;

    public:
        // Constructores
        Muestra();
        Muestra(int idMuestra, int idAnimal, String^ tipo, String^ fechaToma,
            String^ consistencia, String^ colorHeces, String^ olor, String^ parasitos,
            String^ cantidadExtraida, String^ colorSangre, String^ coagulos, String^ contaminacion);

        // Getters y setters
        int getIdMuestra();
        void setIdMuestra(int id);

        int getIdAnimal();
        void setIdAnimal(int id);

        String^ getTipo();
        void setTipo(String^ t);

        String^ getFechaToma();
        void setFechaToma(String^ f);

        // Heces
        String^ getConsistencia();
        void setConsistencia(String^ v);

        String^ getColorHeces();
        void setColorHeces(String^ v);

        String^ getOlor();
        void setOlor(String^ v);

        String^ getParasitos();
        void setParasitos(String^ v);

        // Sangre
        String^ getCantidadExtraida();
        void setCantidadExtraida(String^ v);

        String^ getColorSangre();
        void setColorSangre(String^ v);

        String^ getCoagulos();
        void setCoagulos(String^ v);

        String^ getContaminacion();
        void setContaminacion(String^ v);
    };
}

