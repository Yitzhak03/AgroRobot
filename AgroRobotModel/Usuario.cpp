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
	List<Rol^>^ roles,
	List<Alerta^>^ alerts)
{
	Id = id;
	Nombre = nombre;
	Email = email;
	Contrasenha = contrasenha;
	UltimoAcceso = ultimoAcceso;
	EstadoCuenta = estadoCuenta;
	Roles = roles;
	Alerts = alerts;
}
