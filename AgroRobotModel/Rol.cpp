#include "Rol.h"

using namespace AGROModel;

Rol::Rol() {

}

Rol::Rol(int idRol, String^ nombreRol, String^ permisos) {
	IdRol = idRol;
	NombreRol = nombreRol;
	Permisos = permisos;
}