#include "ParametroNutricional.h"

using namespace AgroRobotModel;

ParametroNutricional::ParametroNutricional() {

}

ParametroNutricional::ParametroNutricional(
    int idParametro,
    String^ nombre,
    String^ rangoSaludable,
    String^ rangoCritico,
    String^ unidadMedida,
    Dieta^ dietaAsociada) 
{
	IdParametro = idParametro;
	Nombre = nombre;
	RangoSaludable = rangoSaludable;
	RangoCritico = rangoCritico;
	UnidadMedida = unidadMedida;
	DietaAsociada = dietaAsociada;

}
