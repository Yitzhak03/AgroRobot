#pragma once
namespace AgroRobotModel {
    using namespace System;

    public ref class Reporte {
    private:
        // Campos existentes (ahora privados)
        int idReporte;
        String^ tipo;
        DateTime fechaGeneracion; // ¡Actualizado a DateTime!
        String^ contenido;

        // Nuevos campos para Dashboard y Filtros
        String^ animalAlias;
        String^ estadoSaludImpacto; // Para la columna "Estado Salud/Impacto"
        String^ estadoGestion;      // Para la columna "Atención/Gestión"

    public:
        Reporte();
        // Constructor actualizado para incluir todos los campos de gestión
        Reporte(
            int idReporte,
            String^ tipo,
            String^ animalAlias,
            DateTime fechaGeneracion,
            String^ contenido,
            String^ estadoSaludImpacto,
            String^ estadoGestion
        );

        // Getters (Lectura)
        int getIdReporte();
        String^ getTipo();
        String^ getAnimalAlias();
        DateTime getFechaGeneracion();
        String^ getContenido();
        String^ getEstadoSaludImpacto();
        String^ getEstadoGestion();

        // Setters (Escritura)
        void setIdReporte(int idReporte);
        void setTipo(String^ tipo);
        void setAnimalAlias(String^ animalAlias);
        void setFechaGeneracion(DateTime fechaGeneracion);
        void setContenido(String^ contenido);
        void setEstadoSaludImpacto(String^ estadoSaludImpacto);
        void setEstadoGestion(String^ estadoGestion);

        // Opcional: Para una representación de texto
        String^ ToString() override;
    };
}