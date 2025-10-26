#pragma once
namespace AgroRobotModel {
    using namespace System;
    using namespace System::Collections::Generic;

    // Forward declaration
    ref class OrdenDistribucion;

    public ref class Dieta {
    public:
        property int Id;
        property int IdAnimal;
        property String^ FechaInicio;
        property String^ Alimentos;
        property String^ Frecuencia;
        property List<OrdenDistribucion^>^ OrdenesDistribucion;
        Dieta();
        Dieta(
            int id,
            int idAnimal,
            String^ fechaInicio,
            String^ alimentos,
            String^ frecuencia,
            List<OrdenDistribucion^>^ ordenesDistribucion
        );
    };
}