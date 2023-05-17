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
	/// <summary>
	/// Print shape infor in many way with Strategy
	/// </summary>
	/// <param name="container"></param>
	/// <param name="file_name"></param>
	/// <param name="expected"></param>
	virtual void execute(vector<SHAPECONTAINER> container, string file_name, int expected) = 0;
};