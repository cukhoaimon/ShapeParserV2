#include "DLLController.h"

DLLController::DLLController()
{
	_hinstance = NULL;
}

DLLController::DLLController(wstring file_path)
{
	this->load(file_path);
}

DLLController::~DLLController()
{
	cout << "~DLLConstroller" << endl;
	FreeLibrary(_hinstance);
}

HINSTANCE DLLController::exec()
{
	return _hinstance;
}

void DLLController::load(wstring file_path) noexcept(false)
{
	_hinstance = LoadLibrary(file_path.c_str());
	
	if (NULL == _hinstance) {
		// TODO: exception
		throw (GetLastError());
	}
}

string DLLController::toString()
{
	return string("DLLController");
}
