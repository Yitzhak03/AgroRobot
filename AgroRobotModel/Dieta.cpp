#include "Dieta.h"

using namespace AgroRobotModel;

Dieta::Dieta() {

}

Dieta::Dieta(
    int id,
    int idAnimal,
    String^ fechaInicio,
    String^ alimentos,
    String^ frecuencia,
    List<OrdenDistribucion^>^ ordenesDistribucion) 
{
	Id = id;
	IdAnimal = idAnimal;
	FechaInicio = fechaInicio;
	Alimentos = alimentos;
	Frecuencia = frecuencia;
	OrdenesDistribucion = ordenesDistribucion;
}
