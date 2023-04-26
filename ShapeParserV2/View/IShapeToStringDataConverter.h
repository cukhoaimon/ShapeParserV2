#pragma once
#include "..\Model\IShape.h"

class IShapeToStringDataConverter
{
public:
	virtual std::wstring convert(IShape*) = 0;

public:
	virtual std::string toString() = 0;
};

