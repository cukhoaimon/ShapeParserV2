#pragma once
#include "..\Model\IShape.h"
#include <tuple>
#include <string>

using std::tuple;
using std::wstring;

typedef tuple<wstring, wstring, wstring, wstring> SHAPECONTAINER;

class IShapeToStringDataConverter
{
public:
	virtual SHAPECONTAINER convert(IShape*) = 0;

public:
	virtual std::string toString() = 0;
};

