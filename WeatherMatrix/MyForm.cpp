#include "MyForm.h"
#include "Matrix.h"
#include <msclr\marshal_cppstd.h>


using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
	
	msclr::interop::marshal_context context;
	std::string arg0 = context.marshal_as<std::string>(args[0]);

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	WeatherMatrix::MyForm form(arg0);
	Application::Run(%form);
}
