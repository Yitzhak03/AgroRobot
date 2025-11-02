#pragma once
#include "Muestra.h"

namespace AgroRobotModel {
    using namespace System;
    using namespace System::Collections::Generic;

    public ref class EstadisticaDiagnostico {
    private:
        String^ categoria;
        int cantidad;
        double porcentaje;

    public:
        EstadisticaDiagnostico();
        EstadisticaDiagnostico(String^ categoria, int cantidad, double porcentaje);

        // Getters y setters
        property String^ Categoria {
            String^ get() { return categoria; }
            void set(String^ value) { categoria = value; }
        }

        property int Cantidad {
            int get() { return cantidad; }
            void set(int value) { cantidad = value; }
        }

        property double Porcentaje {
            double get() { return porcentaje; }
            void set(double value) { porcentaje = value; }
        }
    };

    public ref class ReporteDiagnosticoData {
    private:
        String^ periodo;
        int totalMuestras;
        int totalAnimales;
        List<EstadisticaDiagnostico^>^ porTipoAnalisis;
        List<EstadisticaDiagnostico^>^ porEstadoSalud;
        List<Muestra^>^ muestrasDetalladas;

    public:
        ReporteDiagnosticoData();

        // Getters y setters
        property String^ Periodo {
            String^ get() { return periodo; }
            void set(String^ value) { periodo = value; }
        }

        property int TotalMuestras {
            int get() { return totalMuestras; }
            void set(int value) { totalMuestras = value; }
        }

        property int TotalAnimales {
            int get() { return totalAnimales; }
            void set(int value) { totalAnimales = value; }
        }

        property List<EstadisticaDiagnostico^>^ PorTipoAnalisis {
            List<EstadisticaDiagnostico^>^ get() { return porTipoAnalisis; }
            void set(List<EstadisticaDiagnostico^>^ value) { porTipoAnalisis = value; }
        }

        property List<EstadisticaDiagnostico^>^ PorEstadoSalud {
            List<EstadisticaDiagnostico^>^ get() { return porEstadoSalud; }
            void set(List<EstadisticaDiagnostico^>^ value) { porEstadoSalud = value; }
        }

        property List<Muestra^>^ MuestrasDetalladas {
            List<Muestra^>^ get() { return muestrasDetalladas; }
            void set(List<Muestra^>^ value) { muestrasDetalladas = value; }
        }
    };
}