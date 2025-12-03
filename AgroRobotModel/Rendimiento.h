#pragma once

namespace AgroRobotModel {
	using namespace System;
	using namespace System::Collections::Generic;

	public ref class Rendimiento {
	private:
		int id;

		//Motores
		double horasMotorIzquierdo;
		double horasMotorDerecho;
		double vidaUtilEstimadaMotor = 5000.0;

		//Servomotor
		long ciclosOperacionServo;
		long vidaUtilEstimadaServo = 100000;

	public:
		Rendimiento();
		Rendimiento(int id, double horasMotorIzquiero, double horasMotorDerecho, long ciclosOperacionesServo);

		int getId();
		void setId(int id);

		double getHorasMotorIzquierdo();
		void setHorasMotorIzquierdo(double horas);

		double getHorasMotorDerecho();
		void setHorasMotorDerecho(double horas);

		double getVidaUtilEstimadaMotor();

		long getCiclosOperacionServo();
		void setCiclosOperacionServo(long ciclo);

		long getVidaUtilEstimadaServo();
	};
}