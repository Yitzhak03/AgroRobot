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

Animal::Animal(int idAnimal, String^ especie, double peso, double edad, String^ estadoSalud, String^ ultimaDieta) {
	this->IdAnimal = idAnimal;
	this->Especie = especie;
	this->Peso = peso;
	this->Edad = edad;
	this->EstadoSalud = estadoSalud;
	this->UltimaDieta = ultimaDieta;

	// Inicializar listas y referencias en null
	this->Muestras = gcnew List<Muestra^>();
	this->Dietaa = nullptr;
	this->HistoriasClinicas = gcnew List<HistoriaClinica^>();
	this->UltimaVezAlimentado = "";
	this->VecesAlimentado = 0;
}
