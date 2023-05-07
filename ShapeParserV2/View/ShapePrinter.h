#pragma once

#include "..\..\utils\utils.h"
#include "..\Model\IShape.h"

class ShapePrinter
{
private:
	vector<TUPLEOFSHAPESTRING> _holder;

public:
	ShapePrinter();

	wstring pattern(TUPLEOFSHAPESTRING);
	void push(TUPLEOFSHAPESTRING);
	void clear();
	void print();
};

