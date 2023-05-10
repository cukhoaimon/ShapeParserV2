#pragma once
#include "..\..\utils\utils.h"
#include "..\Object.h"

class DLLController
	: public Object
{
private:
	HINSTANCE _hinstance;

public:
	DLLController();
	DLLController(wstring);
	~DLLController();

	HINSTANCE exec();
	
	void load(wstring) noexcept(false);

	string toString();
};