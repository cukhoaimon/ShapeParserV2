#include "ShapeFactory.h"

void ShapeFactory::registerWith(string type, IParser* parser)
{
	if (_prototypes.contains(type) == false) {
		_prototypes.insert({ type, parser });
	}
}

IParser* ShapeFactory::select(string type)
{
	IParser* result = nullptr;

	if (_prototypes.contains(type)) {
		result = _prototypes[type];
	}

	return result;
}

string ShapeFactory::toString()
{
	return string("ShapeFactory");
}
