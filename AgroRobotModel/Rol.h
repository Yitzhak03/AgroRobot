#pragma once
namespace AgroRobotModel {
    using namespace System;
    using namespace System::Collections::Generic;

    public ref class Rol {
    
    public:
        property int Id;
        property String^ Nombre;
        List<bool>^ Permisos;
    
    public: 
        Rol();
        Rol(int id, String^ nombre);

        int GetId();
        void SetId(int id);

        String^ GetNombre();
        void SetNombre(String^ nombre);

        List<bool>^ GetPermisos();
        void SetPermisos(List<bool>^ listaPermisos);

        virtual String^ ToString() override {
            return Nombre;         
        }
    };
}