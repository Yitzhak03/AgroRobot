#include "Administrador.h"

using namespace AgroRobotModel;

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