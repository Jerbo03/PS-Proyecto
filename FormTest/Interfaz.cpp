#include "Interfaz.h"

using namespace System;
using namespace System::Windows::Forms;

int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	FormTest::Interfaz frm;

	Application::Run(% frm);
	return 0;
}