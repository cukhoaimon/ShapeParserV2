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

	void print(vector<SHAPECONTAINER> container, string file_name, int expected);

	string toString() override;
};

