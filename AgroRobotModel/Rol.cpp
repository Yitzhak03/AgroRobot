#include "Rol.h"

using namespace AgroRobotModel;

Rol::Rol() {

}

Rol::Rol(int id, String^ nombre, String^ permisos) {
	Id = id;
	Nombre = nombre;
	Permisos = permisos;
}