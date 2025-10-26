#include "Administrador.h"

using namespace AGROModel;

Administrador::Administrador() {
}

Administrador::Administrador(
	String^ privilegios, 
	String^ areaResponsabilidad, 
	List<ConfiguracionSistema^>^ configuracionesSistema
) 
{
	Privilegios = privilegios;
	AreaResponsabilidad = areaResponsabilidad;
	ConfiguracionesSistema = configuracionesSistema;
}