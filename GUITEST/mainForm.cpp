#include "mainForm.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute] //Main: 진입점에서 설정한 이름

void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	//GUITEST: CLR 프로젝트 이름
	//mainForm: cpp 파일 이름
	GUITEST::mainForm form;
	Application::Run(% form);
}