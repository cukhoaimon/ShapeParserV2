#pragma once

#include "..\Object.h"
#include "IStrategy.h"
#include "ColumnStrategy.h"
#include "DetailStrategy.h"

class ShapePrinter 
	: public Object
{
private:
	IStrategy* _strategy;

public:
	ShapePrinter();

	void setStrategy(IStrategy*);

	/// <summary>
	/// Print information of shape to screen with
	/// strategy that registed before.
	/// </summary>
	/// <param name="container">: A vector of SHAPECONTAINER want to print to screen</param>
	/// <param name="file_name">: The name of source input file</param>
	/// <param name="expected">: The number of shape in source file</param>
	void print(vector<SHAPECONTAINER> container, string file_name, int expected);

	string toString() override;
};

