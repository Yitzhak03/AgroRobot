#include "Ganadero.h"

using namespace AGROModel;

Ganadero::Ganadero() {

}

Ganadero::Ganadero(
	String^ ubicacionGranja,
	Robot^ robott) 
{
	UbicacionGranja = ubicacionGranja;
	Robott = robott;
}
