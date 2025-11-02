#pragma once
#include "Dieta.h"
#include "OrdenDistribucion.h"

namespace AgroRobotModel {
    using namespace System;
    using namespace System::Collections::Generic;

    public ref class EstadisticaAlimentacion {
    private:
        String^ categoria;
        int cantidad;
        double porcentaje;

    public:
        EstadisticaAlimentacion();
        EstadisticaAlimentacion(String^ categoria, int cantidad, double porcentaje);

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

    public ref class DietaResumenData {
    private:
        int idDieta;
        int idAnimal;
        String^ alimentos;
        String^ frecuencia;
        String^ fechaInicio;
        String^ prioridad;

    public:
        DietaResumenData();
        DietaResumenData(int idDieta, int idAnimal, String^ alimentos, String^ frecuencia, String^ fechaInicio, String^ prioridad);

        // Getters y setters
        property int IdDieta {
            int get() { return idDieta; }
            void set(int value) { idDieta = value; }
        }

        property int IdAnimal {
            int get() { return idAnimal; }
            void set(int value) { idAnimal = value; }
        }

        property String^ Alimentos {
            String^ get() { return alimentos; }
            void set(String^ value) { alimentos = value; }
        }

        property String^ Frecuencia {
            String^ get() { return frecuencia; }
            void set(String^ value) { frecuencia = value; }
        }

        property String^ FechaInicio {
            String^ get() { return fechaInicio; }
            void set(String^ value) { fechaInicio = value; }
        }

        property String^ Prioridad {
            String^ get() { return prioridad; }
            void set(String^ value) { prioridad = value; }
        }
    };

    public ref class ReporteAlimentacionData {
    private:
        String^ periodo;
        int totalDietas;
        int dietasActivas;
        int dietasInactivas;
        List<EstadisticaAlimentacion^>^ porTipoDieta;
        List<EstadisticaAlimentacion^>^ topAlimentos;
        List<DietaResumenData^>^ dietasDetalladas;

    public:
        ReporteAlimentacionData();

        // Getters y setters
        property String^ Periodo {
            String^ get() { return periodo; }
            void set(String^ value) { periodo = value; }
        }

        property int TotalDietas {
            int get() { return totalDietas; }
            void set(int value) { totalDietas = value; }
        }

        property int DietasActivas {
            int get() { return dietasActivas; }
            void set(int value) { dietasActivas = value; }
        }

        property int DietasInactivas {
            int get() { return dietasInactivas; }
            void set(int value) { dietasInactivas = value; }
        }

        property List<EstadisticaAlimentacion^>^ PorTipoDieta {
            List<EstadisticaAlimentacion^>^ get() { return porTipoDieta; }
            void set(List<EstadisticaAlimentacion^>^ value) { porTipoDieta = value; }
        }

        property List<EstadisticaAlimentacion^>^ TopAlimentos {
            List<EstadisticaAlimentacion^>^ get() { return topAlimentos; }
            void set(List<EstadisticaAlimentacion^>^ value) { topAlimentos = value; }
        }

        property List<DietaResumenData^>^ DietasDetalladas {
            List<DietaResumenData^>^ get() { return dietasDetalladas; }
            void set(List<DietaResumenData^>^ value) { dietasDetalladas = value; }
        }
    };
}