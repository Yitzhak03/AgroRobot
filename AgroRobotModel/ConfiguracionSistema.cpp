#include "ConfiguracionSistema.h"

using namespace AgroRobotModel;

ConfiguracionSistema::ConfiguracionSistema() {

}

ConfiguracionSistema::ConfiguracionSistema(
    String^ horarioOperacion,
    String^ frecuenciaAnalisis,
    String^ umbralesAlerta,
    Analisis^ analisisDatos) 
{
	HorarioOperacion = horarioOperacion;
	FrecuenciaAnalisis = frecuenciaAnalisis;
	UmbralesAlerta = umbralesAlerta;
	AnalisisDatos = analisisDatos;
}
