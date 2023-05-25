#include <windows.h>
#include <objbase.h>
#include "pch.h"
#include "TriangleParser.h"
#include "TriangleToStringConverter.h"

// Define the Shape interface
extern "C" {
    SHAPE_API IParser* __stdcall getParserInstance()
    {
        IParser* result = TriangleParser::getInstance();
        return result;
    }

    SHAPE_API IShapeToStringDataConverter* __stdcall getConverterInstance()
    {
        IShapeToStringDataConverter* result = TriangleToStringConverter::getInstance();
        return result;
    }
}