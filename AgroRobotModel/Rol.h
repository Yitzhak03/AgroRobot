#pragma once
namespace AGROModel {
    using namespace System;

    public ref class Rol {
    public: 
        property int IdRol;
        property String^ NombreRol;
        property String^ Permisos;
        Rol();
        Rol(
            int idRol,
            String^ nombreRol,
            String^ permisos
        );
    };
}