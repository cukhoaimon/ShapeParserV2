#pragma once
#include "..\Model\IShape.h"
#include <tuple>
#include <string>

using std::tuple;
using std::wstring;

typedef tuple<wstring, wstring, wstring, wstring> TUPLEOFSHAPESTRING;

class IShapeToStringDataConverter
{
public:
	virtual TUPLEOFSHAPESTRING convert(IShape*) = 0;

public:
	virtual std::string toString() = 0;
};

