#include "Muestra.h"

using namespace AgroRobotModel;

Muestra::Muestra() {

}

Muestra::Muestra(
    int idMuestra,
    int idAnimal,
    String^ tipo,
    String^ fechaToma,
    String^ datosCrudos,
    Ganadero^ ganaderoo) 
{
	IdMuestra = idMuestra;
	IdAnimal = idAnimal;
	Tipo = tipo;
	FechaToma = fechaToma;
	DatosCrudos = datosCrudos;
	Ganaderoo = ganaderoo;
}
