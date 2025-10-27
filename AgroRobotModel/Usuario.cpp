#include "Usuario.h"

using namespace AgroRobotModel;

Usuario::Usuario() {

}
Usuario::Usuario(
	int id,
	String^ nombre,
	String^ email,
	String^ contrasenha,
	String^ ultimoAcceso,
	String^ estadoCuenta,
	List<int>^ idsRoles,
	List<int>^ idsAlertas)
{
	Id = id;
	Nombre = nombre;
	Email = email;
	Contrasenha = contrasenha;
	UltimoAcceso = ultimoAcceso;
	EstadoCuenta = estadoCuenta;
	IdsRoles = idsRoles;
	IdsAlertas = idsAlertas;
}
