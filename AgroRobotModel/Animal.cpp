#include "Animal.h"

using namespace AgroRobotModel;

Animal::Animal()
{

}

Animal::Animal(
	int idAnimal,
	String^ especie,
	double peso,
	double edad,
	String^ estadoSalud,
	String^ ultimaDieta,
	List<Muestra^>^ muestras,
	Dieta^ dietaa,
	List<HistoriaClinica^>^ historiasClinicas,
	String^ ultimaVezAlimentado)
{
	IdAnimal = idAnimal;
	Especie = especie;
	Peso = peso;
	Edad = edad;
	EstadoSalud = estadoSalud;
	UltimaDieta = ultimaDieta;
	Muestras = muestras;
	Dietaa = dietaa;
	HistoriasClinicas = historiasClinicas;
	UltimaVezAlimentado = ultimaVezAlimentado;
}
