#include "mainForm.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute] //Main: ���������� ������ �̸�

void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	//GUITEST: CLR ������Ʈ �̸�
	//mainForm: cpp ���� �̸�
	GUITEST::mainForm form;
	Application::Run(% form);
}