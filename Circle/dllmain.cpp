#include <windows.h>
#include <objbase.h>
#include "pch.h"
#include "CircleParser.h"
#include "CircleToStringConverter.h"

// Define the Shape interface
extern "C" {
    /// <summary>
    /// Get an instance of CircleParser 
    /// </summary>
    /// <returns>Address of CircleParser</returns>
    SHAPE_API IParser* __stdcall getParserInstance()
    {
        IParser* result = CircleParser::getInstance();
        return result;
    }

    /// <summary>
    /// Get an instance of circle-converter 
    /// </summary>
    /// <returns>Address of circle-converter</returns>
    SHAPE_API IShapeToStringDataConverter* __stdcall getConverterInstance()
    {
        IShapeToStringDataConverter* result = CircleToStringConverter::getInstance();
        return result;
    }
}