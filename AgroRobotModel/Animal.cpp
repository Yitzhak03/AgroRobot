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
	String^ ultimaVezAlimentado,
	int vecesAlimentado)
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
	VecesAlimentado = vecesAlimentado;
}

Animal::Animal(int idAnimal, String^ especie) {
	IdAnimal = idAnimal;
	Especie = especie;
	Peso = 0.0;
	Edad = 0.0;
	EstadoSalud = "";
	UltimaDieta = "";
	Muestras = gcnew List<Muestra^>();
	Dietaa = nullptr;
	HistoriasClinicas = gcnew List<HistoriaClinica^>();
}
