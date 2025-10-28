#pragma once

namespace AgroRobotController {
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace AgroRobotModel;

	public ref class GestorNutricionalController {
	private:
		List<Dieta^>^ listaDietas;
		List<Animal^>^ listaAnimales;
		List<OrdenDistribucion^>^ listaOrdenes;

	public:
		/*Inicio*/
		GestorNutricionalController();

		/*Ingreso de usuario*/
		/*bool validarIngresoNutricional(String^ usuario, String^ contraseña);*/

		/*Animal*/
		List<Animal^>^ obtenerTodosAnimales();
		void registrarAnimal(Animal^ animal);
		bool existeAnimal(int idAnimal);
		Animal^ consultarAnimalporId(int idAnimal);
		void escribirArchivoAnimal();
		List<Animal^>^ consultarAnimalporIdEspecie(int idAnimal, String^ especie);
		bool modificarAnimal(int idAnimal, String^ especie, double peso, double edad, String^ estadoSalud, String^ ultimaDieta);
		bool eliminarAnimal(int idAnimal);
		void closeAnimal();

		/*Dieta*/
		List<Dieta^>^ obtenerTodasDietas();
		void registrarDieta(Dieta^ dieta);
		bool existeDieta(int id);
		Dieta^ consultarDietaporId(int id);
		void escribirArchivoDieta();
		bool modificarDieta(int id, int idAnimal, String^ fechaInicio, String^ alimentos, String^ frecuencia);
		bool eliminarDieta(int id);
		void closeDieta();

		/*AlertaDeConsumo*/
		void enviarOrdenAlimentacion(int idDieta, String^ prioridad);
		String^ verificarPesoAnimal(int idAnimal, double pesoEsperado, double peso);
		/*void recibirNuevaDieta(Dieta^ nuevaDieta);
		void generarAlerta(String^ mensaje);*/
	};
}
