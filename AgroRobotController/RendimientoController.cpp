#include "RendimientoController.h"

using namespace AgroRobotController;
using namespace System::IO;


RendimientoController::RendimientoController() {
	String^ path = "rendimiento.txt";
	if (!File::Exists(path)) File::WriteAllText(path, "");

	array<String^>^ lineas = File::ReadAllLines(path);
	for each (String ^ linea in lineas) {
		if (String::IsNullOrWhiteSpace(linea)) continue;
		array<String^>^ datos = linea->Split(';');
		if (datos->Length < 4) continue; // Validación básica

		int id = Convert::ToInt32(datos[0]);
		double horasMotorIzquierdo = Convert::ToDouble(datos[1]);
		double horasMotorDerecho = Convert::ToDouble(datos[2]);
		long ciclosServo = Convert::ToInt64(datos[3]);

		Rendimiento^ rendimiento = gcnew Rendimiento(id, horasMotorIzquierdo, horasMotorDerecho, ciclosServo);
		this->listaRendimiento->Add(rendimiento);
	}
}

List<Rendimiento^>^ RendimientoController::buscarTodos() {
	return this->listaRendimiento;
}

void RendimientoController::agregarRendimiento(Rendimiento^ rendimiento) {
	this->listaRendimiento->Add(rendimiento);
}

void RendimientoController::actualizarxAnimal(int cantidadAnimales) {
	double nuevasHorasIzq = this->listaRendimiento[0]->getHorasMotorIzquierdo() + segPorAlimentacion / 3600;
	double nuevasHorasDer = this->listaRendimiento[0]->getHorasMotorDerecho() + segPorAlimentacion / 3600;
	int ciclos = this->listaRendimiento[0]->getCiclosOperacionServo() + 1;

	this->listaRendimiento[0]->setHorasMotorIzquierdo(nuevasHorasIzq);
	this->listaRendimiento[0]->setHorasMotorDerecho(nuevasHorasDer);
	this->listaRendimiento[0]->setCiclosOperacionServo(ciclos);
}

void RendimientoController::escribirArchivo() {
	String^ path = "rendimiento.txt";
	array<String^>^ lineasArchivo = gcnew array<String^>(this->listaRendimiento->Count);
	for (int i = 0; i < this->listaRendimiento->Count; i++) {
		Rendimiento^ rendimiento = this->listaRendimiento[i];
		lineasArchivo[i] = rendimiento->getId() + ";" + rendimiento->getHorasMotorIzquierdo() + ";" +
			rendimiento->getHorasMotorDerecho() + ";" + rendimiento->getVidaUtilEstimadaMotor() + ";" + 
			rendimiento->getCiclosOperacionServo() + ";" + rendimiento->getVidaUtilEstimadaServo();
	}
	File::WriteAllLines(path, lineasArchivo);
}