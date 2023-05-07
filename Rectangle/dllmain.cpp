#include <windows.h>
#include <objbase.h>
#include "pch.h"
#include "RectangleParser.h"
#include "RectangleToStringConverter.h"

// Define the Shape interface
extern "C" {
    SHAPE_API IParser* __stdcall getParserInstance()
    {
        IParser* result = new RectangleParser();
        return result;
    }

    SHAPE_API IShapeToStringDataConverter* __stdcall getConverterInstance()
    {
        IShapeToStringDataConverter* result = new RectangleToStringConverter();
        return result;
    }
}