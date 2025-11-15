#pragma once
#include "Animal.h"

namespace AgroRobotModel {

    using namespace System;

    public ref class Muestra {
    private:
        // Comunes
        int idMuestra;
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

        // Referencia al animal
        Animal^ animal;

    public:
        // Constructores
        Muestra();
        Muestra(int idMuestra, String^ tipo, String^ fechaToma,
            String^ consistencia, String^ colorHeces, String^ olor, String^ parasitos,
            String^ cantidadExtraida, String^ coagulos, String^ contaminacion,
            String^ colorSangre, Animal^ animal);

        // Getters y setters
        int getIdMuestra();
        void setIdMuestra(int idMuestra);

        String^ getTipo();
        void setTipo(String^ tipo);

        String^ getFechaToma();
        void setFechaToma(String^ fechaToma);

        // Heces
        String^ getConsistencia();
        void setConsistencia(String^ consistencia);

        String^ getColorHeces();
        void setColorHeces(String^ colorHeces);

        String^ getOlor();
        void setOlor(String^ olor);

        String^ getParasitos();
        void setParasitos(String^ parasitos);

        // Sangre
        String^ getCantidadExtraida();
        void setCantidadExtraida(String^ cantidadExtraida);

        String^ getColorSangre();
        void setColorSangre(String^ colorSangre);

        String^ getCoagulos();
        void setCoagulos(String^ coagulos);

        String^ getContaminacion();
        void setContaminacion(String^ contaminacion);

        // Animal
        Animal^ getAnimal();
        void setAnimal(Animal^ animal);

        // Propiedades derivadas del animal
        int getIdAnimal();
        String^ getEspecie();
    };
}

