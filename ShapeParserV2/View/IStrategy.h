#pragma once
#include "..\Object.h"
#include "..\..\utils\utils.h"

/*
=============================== Define class ===============================
*/

class IStrategy 
	: public Object 
{
public:
	virtual void execute(vector<SHAPECONTAINER> container, string file_name, int expected) = 0;
};