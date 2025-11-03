#include "HistoriaClinica.h"

using namespace AgroRobotModel;

HistoriaClinica::HistoriaClinica() {
}

HistoriaClinica::HistoriaClinica(
    int idAnimal,
    String^ registrarAnalisis,
    String^ registrarDietas,
    String^ evolucionSalud,
    String^ planesNutricionales,
    Reporte^ reporteAsociado,
	List<Diagnostico^>^ analisisRealizados
) 
{
	IdAnimal = idAnimal;
	RegistrarAnalisis = registrarAnalisis;
	RegistrarDietas = registrarDietas;
	EvolucionSalud = evolucionSalud;
	PlanesNutricionales = planesNutricionales;
	ReporteAsociado = reporteAsociado;
	AnalisisRealizados = analisisRealizados;
}
