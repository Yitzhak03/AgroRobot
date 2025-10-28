#pragma once
namespace AgroRobotController {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace AgroRobotModel;
    using namespace System::IO;

    public ref class ReporteController {
    private:
        List<Reporte^>^ listaReportes;

    public:
        ReporteController();
        // Persistencia
        void escribirArchivo();

        // Operación principal para la vista (Dashboard)
        List<Reporte^>^ ConsultarReportesPorFiltros(
            String^ animalAlias,
            DateTime fechaInicio,
            DateTime fechaFin,
            String^ tipoAnalisis,
            String^ estadoSalud
        );

        // Operaciones CRUD básicas (Mantenimiento)
        List<Reporte^>^ ObtenerTodosReportes();
        void AgregarReporte(Reporte^ reporte);
        Reporte^ ConsultarReportePorId(int id);
        bool ModificarReporte(Reporte^ reporte);
        bool EliminarReporte(int id);

        void CloseReporte();
    };
}