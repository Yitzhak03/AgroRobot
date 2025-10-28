#include "frmMain.h"
//Para probar otras ventanas descomentar la que se quiera probar
//#include "frmMenu.h"
//#include "frmNuevoUsuario.h"
//#include "frmNuevoInsumo.h"
//#include "frmMantInsumo.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace AgroRobotView;

void main(array <String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	frmMain ventana; /*Estoy creando el objeto ventana que va a ser del tipo frmPrincipal*/
	Application::Run(% ventana); /*Aqui estoy ejecutando la ventana inicial*/
}