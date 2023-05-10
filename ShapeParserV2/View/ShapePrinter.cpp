#include "ShapePrinter.h"

ShapePrinter::ShapePrinter()
{
	_strategy = nullptr;
}

void ShapePrinter::setStrategy(IStrategy* strategy)
{
	if (_strategy != nullptr) {
		delete _strategy;
	}

	_strategy = strategy;
}

void ShapePrinter::print(vector<SHAPECONTAINER> container, string file_name, int expected)
{
	_strategy->execute(container, file_name, expected);
}

string ShapePrinter::toString()
{
	return string("ShapePrinter");
}
