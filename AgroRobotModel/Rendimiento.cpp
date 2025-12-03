#include "Rendimiento.h"

using namespace AgroRobotModel;

Rendimiento::Rendimiento() {
	this->id = 0;
	this->horasMotorIzquierdo = 0.0;
	this->horasMotorDerecho = 0.0;
	this->ciclosOperacionServo = 0;
}

Rendimiento::Rendimiento(int id, double horasMotorIzquiero, double horasMotorDerecho, long ciclosOperacionesServo) {
	this->id = id;
	this->horasMotorIzquierdo = horasMotorIzquiero;
	this->horasMotorDerecho = horasMotorDerecho;
	this->ciclosOperacionServo = ciclosOperacionesServo;
}

int Rendimiento::getId() {
	return this->id;
}

void Rendimiento::setId(int id) {
	this->id = id;
}


double Rendimiento::getHorasMotorIzquierdo() {
	return this->horasMotorIzquierdo;
}

void Rendimiento::setHorasMotorIzquierdo(double horas) {
	this->horasMotorIzquierdo = horas;
}


double Rendimiento::getHorasMotorDerecho() {
	return this->horasMotorDerecho;
}

void Rendimiento::setHorasMotorDerecho(double horas) {
	this->horasMotorDerecho = horas;
}


double Rendimiento::getVidaUtilEstimadaMotor() {
	return this->vidaUtilEstimadaMotor;
}


long Rendimiento::getCiclosOperacionServo() {
	return this->ciclosOperacionServo;
}

void Rendimiento::setCiclosOperacionServo(long ciclos) {
	this->ciclosOperacionServo = ciclos;
}


long Rendimiento::getVidaUtilEstimadaServo() {
	return this->vidaUtilEstimadaServo;
}