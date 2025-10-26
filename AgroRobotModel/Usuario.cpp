#include "Usuario.h"

using namespace AGROModel;

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
	Alerta^ alertasUsuario) 
{
	Id = id;
	Nombre = nombre;
	Email = email;
	Contrasenha = contrasenha;
	UltimoAcceso = ultimoAcceso;
	EstadoCuenta = estadoCuenta;
	Roles = roles;
	AlertasUsuario = alertasUsuario;
}
