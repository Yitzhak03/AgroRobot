#include "StockInsumoController.h"
#include "InsumoController.h"
#include "AlmacenController.h"
using namespace AgroRobotController;
using namespace System::IO;
StockInsumoController::StockInsumoController()
{

}
List<StockInsumo^>^ StockInsumoController::readTxt()
{
	// Leer txt de la forma:
	// Id(int);IdInsumo(int);IdAlmacen(int);Stock(String^);LimiteBajo(String^);LimiteAlto(String^)
	List<StockInsumo^>^ lista = gcnew List<StockInsumo^>();
	String^ path = "stocks.txt";
	array<String^>^ lineas = File::ReadAllLines(path);
	for each (String ^ linea in lineas) {
		array<String^>^ datos = linea->Split(';');
		StockInsumo^ stockInsumo = gcnew StockInsumo();
		stockInsumo->Id = Convert::ToInt32(datos[0]);
		InsumoController^ insumoController = gcnew InsumoController();
		stockInsumo->Insumoo = insumoController->buscarPorId(Convert::ToInt32(datos[1]));
		AlmacenController^ almacenController = gcnew AlmacenController();
		stockInsumo->Almacenn = almacenController->buscarPorId(Convert::ToInt32(datos[2]));
		stockInsumo->Stock = Convert::ToSingle(datos[3]);
		stockInsumo->LimiteBajo = Convert::ToSingle(datos[4]);
		stockInsumo->LimiteAlto = Convert::ToSingle(datos[5]);
		lista->Add(stockInsumo);
	}
	return lista;
}
StockInsumo^ StockInsumoController::buscarPorId(int id)
{
	List<StockInsumo^>^ lista = readTxt();
	for each (StockInsumo ^ s in lista) {
		if (s->Id == id) {
			return s;
		}
	}
	return nullptr;
}
List<StockInsumo^>^ StockInsumoController::buscarPorIdInsumo(int idInsumo)
{
	List<StockInsumo^>^ lista = readTxt();
	List<StockInsumo^>^ resultados = gcnew List<StockInsumo^>();
	for each (StockInsumo ^ s in lista) {
		if (s->Insumoo->Id == idInsumo) {
			resultados->Add(s);
		}
	}
	return resultados;
}
List<StockInsumo^>^ StockInsumoController::buscarPorIdAlmacen(int idAlmacen)
{
	List<StockInsumo^>^ lista = readTxt();
	List<StockInsumo^>^ resultados = gcnew List<StockInsumo^>();
	for each (StockInsumo ^ s in lista) {
		if (s->Almacenn->Id == idAlmacen) {
			resultados->Add(s);
		}
	}
	return resultados;
}
int StockInsumoController::cantidadInsumosEnAlmacen(int idAlmacen)
{
	List<StockInsumo^>^ lista = readTxt();
	int contador = 0;
	for each (StockInsumo ^ s in lista) {
		if (s->Almacenn->Id == idAlmacen) {
			contador++;
		}
	}
	return contador;
}
