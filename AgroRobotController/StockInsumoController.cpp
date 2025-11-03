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
void StockInsumoController::writeTxt(List<StockInsumo^>^ lista)
{
	String^ path = "stocks.txt";
	List<String^>^ lineas = gcnew List<String^>();
	for each (StockInsumo ^ s in lista) {
		String^ linea = Convert::ToString(s->Id) + ";" +
			Convert::ToString(s->Insumoo->Id) + ";" +
			Convert::ToString(s->Almacenn->Id) + ";" +
			Convert::ToString(s->Stock) + ";" +
			Convert::ToString(s->LimiteBajo) + ";" +
			Convert::ToString(s->LimiteAlto);
		lineas->Add(linea);
	}
	File::WriteAllLines(path, lineas->ToArray());
}
int StockInsumoController::generarNuevoId()
{
	List<StockInsumo^>^ lista = readTxt();
	int maxId = 0;
	for each (StockInsumo ^ s in lista) {
		if (s->Id > maxId) {
			maxId = s->Id;
		}
	}
	return maxId + 1;
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
void StockInsumoController::agregarStockInsumo(StockInsumo^ stockInsumo)
{
	List<StockInsumo^>^ lista = readTxt();
	lista->Add(stockInsumo);
	// Escribir de nuevo el archivo
	writeTxt(lista);
}
void StockInsumoController::actualizarStockInsumo(StockInsumo^ stockInsumo)
{
	List<StockInsumo^>^ lista = readTxt();
	for (int i = 0; i < lista->Count; i++) {
		if (lista[i]->Id == stockInsumo->Id) {
			lista[i] = stockInsumo;
			break;
		}
	}
	// Escribir de nuevo el archivo
	writeTxt(lista);
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
StockInsumo^ StockInsumoController::buscarPorIdInsumoYAlmacen(int idInsumo, int idAlmacen)
{
	List<StockInsumo^>^ lista = readTxt();
	for each (StockInsumo ^ s in lista) {
		if (s->Insumoo->Id == idInsumo && s->Almacenn->Id == idAlmacen) {
			return s;
		}
	}
	return nullptr;
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
