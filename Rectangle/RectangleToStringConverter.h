#pragma once
#include "pch.h"

class RectangleToStringConverter :
    public IShapeToStringDataConverter
{
public:
	TUPLEOFSHAPESTRING convert(IShape*) ;

public:
	std::string toString();
};

