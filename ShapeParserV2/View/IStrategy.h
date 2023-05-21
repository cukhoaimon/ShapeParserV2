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
	/// <param name="container">: A vector of SHAPECONTAINER want to print to screen</param>
	/// <param name="file_name">: The name of source input file</param>
	/// <param name="expected">: The number of shape in source file</param>
	virtual void execute(vector<SHAPECONTAINER> container, string file_name, int expected) = 0;
};