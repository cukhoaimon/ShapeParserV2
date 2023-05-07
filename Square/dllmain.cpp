#include <windows.h>
#include <objbase.h>
#include "pch.h"
#include "SquareParser.h"
#include "SquareToStringConverter.h"

// Define the Shape interface
extern "C" {
    SHAPE_API IParser* __stdcall getParserInstance()
    {
        IParser* result = SquareParser::getInstance();
        return result;
    }

    SHAPE_API IShapeToStringDataConverter* __stdcall getConverterInstance()
    {
        IShapeToStringDataConverter* result = SquareToStringConverter::getInstance();
        return result;
    }
}