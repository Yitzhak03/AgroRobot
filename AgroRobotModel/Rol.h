#pragma once
namespace AgroRobotModel {
    using namespace System;

    public ref class Rol {
    public: 
        property int Id;
        property String^ Nombre;
        property String^ Permisos;
        Rol();
        Rol(
            int id,
            String^ nombre,
            String^ permisos
        );
    };
}