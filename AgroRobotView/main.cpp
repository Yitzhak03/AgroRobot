#include "frmMain.h"
//Para probar otras ventanas descomentar la que se quiera probar
//#include "frmMenu.h"
//#include "frmNuevoUsuario.h"
//#include "frmNuevoInsumo.h"
//#include "frmMantInsumo.h"
//#include "frmMantAlmacen.h"
//#include "frmReporteInsumosXalmacen.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace AgroRobotView;


[STAThreadAttribute]
void main(array <String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	frmMain ventana;
	Application::Run(% ventana); 
}