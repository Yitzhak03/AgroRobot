#pragma once
#include "Usuario.h"
namespace AGROModel {
    using namespace System;

    public ref class RegistroActividad {
    public: 
        property int IdRegistro;
        property int IdUsuario;
        property String^ FechaHora;
        property String^ TipoAccion;
        property String^ Descripcion;
		property Usuario^ Usuarioo;
        RegistroActividad();
        RegistroActividad(
            int idRegistro,
            int idUsuario,
            String^ fechaHora,
            String^ tipoAccion,
            String^ descripcion,
            Usuario^ usuarioo
        );
    };
}