//#include "frmMain.h"
#include "frmMenu.h"
//#include "frmNuevoUsuario.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace AgroRobotView;

void main(array <String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	frmMenu ventana; /*Estoy creando el objeto ventana que va a ser del tipo frmPrincipal*/
	Application::Run(% ventana); /*Aqui estoy ejecutando la ventana inicial*/
}