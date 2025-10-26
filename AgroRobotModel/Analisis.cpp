#include "Analisis.h"
#include "Muestra.h"    // include real porque aquí necesitamos la definición completa
#include "Dieta.h"      // include real para usar Dieta en implementaciones

using namespace AGROModel;

Analisis::Analisis()
{
    Muestras = gcnew List<Muestra^>();
    DietaAsociada = nullptr;
}

Analisis::Analisis(
    int id,
    int idMuestra,
    String^ resultados,
    String^ observaciones,
    String^ diagnosticoGenerado,
    List<Muestra^>^ muestras,
    Dieta^ dietaAsociada
)
{
    Id = id;
    IdMuestra = idMuestra;
    Resultados = resultados;
    Observaciones = observaciones;
    DiagnosticoGenerado = diagnosticoGenerado;
    Muestras = muestras;
    DietaAsociada = dietaAsociada;
}