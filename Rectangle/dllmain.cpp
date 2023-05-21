#include <windows.h>
#include <objbase.h>
#include "pch.h"
#include "RectangleParser.h"
#include "RectangleToStringConverter.h"

// Define the Shape interface
extern "C" {
    /// <summary>
    /// Get an instance of CircleParser 
    /// </summary>
    /// <returns>Address of CircleParser</returns>
    SHAPE_API IParser* __stdcall getParserInstance()
    {
        IParser* result = RectangleParser::getInstance();
        return result;
    }

    /// <summary>
    /// Get an instance of circle-converter 
    /// </summary>
    /// <returns>Address of circle-converter</returns>
    SHAPE_API IShapeToStringDataConverter* __stdcall getConverterInstance()
    {
        IShapeToStringDataConverter* result = RectangleToStringConverter::getInstance();
        return result;
    }
}