#include "Robot.h"

using namespace AgroRobotModel;

Robot::Robot()
{

}

Robot::Robot(
	int id,
	String^ estado,
	String^ bateria,
	String^ ubicacionActual,
	Animal^ animalAsignado,
	RegistroActividad^ registroActividadd)
{
	Id = id;
	Estado = estado;
	Bateria = bateria;
	UbicacionActual = ubicacionActual;
	AnimalAsignado = animalAsignado;
	RegistroActividadd = registroActividadd;
}

