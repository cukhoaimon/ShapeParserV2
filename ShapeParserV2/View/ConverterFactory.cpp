#include "ConverterFactory.h"

void ConverterFactory::registerWith(
	string type,
	IShapeToStringDataConverter* converter)
{
	if (!_prototypes.contains(type)) {
		_prototypes.insert({ type, converter });
	}
}

IShapeToStringDataConverter* ConverterFactory::select(string type)
{
	IShapeToStringDataConverter* result = nullptr;

	if (_prototypes.contains(type)) {
		result = _prototypes[type];
	}

	return result;
}