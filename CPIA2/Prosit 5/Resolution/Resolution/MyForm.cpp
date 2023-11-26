#include "MyForm.h"
#include <thread>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void WinMain(void) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	testWin::MyForm monFormulaire;
	Application::Run(% monFormulaire);
}