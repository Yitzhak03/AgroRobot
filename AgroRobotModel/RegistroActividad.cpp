#include "RegistroActividad.h"

using namespace AGROModel;

RegistroActividad::RegistroActividad() {

}

RegistroActividad::RegistroActividad(
    int idRegistro,
    int idUsuario,
    String^ fechaHora,
    String^ tipoAccion,
    String^ descripcion,
    Usuario^ usuarioo) 
{
	IdRegistro = idRegistro;
	IdUsuario = idUsuario;
	FechaHora = fechaHora;
	TipoAccion = tipoAccion;
	Descripcion = descripcion;
	Usuarioo = usuarioo;
}
