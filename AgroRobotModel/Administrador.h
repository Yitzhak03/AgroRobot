#pragma once
#include "Usuario.h"
#include "ConfiguracionSistema.h"
namespace AgroRobotModel {
    using namespace System;
    using namespace System::Collections::Generic;
    public ref class Administrador : public Usuario {
    public:
        property String^ Privilegios;
        property String^ AreaResponsabilidad;
        property List<ConfiguracionSistema^>^ ConfiguracionesSistema;
        Administrador();
        Administrador(
            String^ privilegios,
            String^ areaResponsabilidad,
            List<ConfiguracionSistema^>^ configuracionesSistema
        );
    };
}