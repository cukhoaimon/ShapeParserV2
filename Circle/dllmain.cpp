#include <windows.h>
#include <objbase.h>
#include "pch.h"
#include "CircleParser.h"
#include "CircleToStringConverter.h"

// Define the Shape interface
extern "C" {
    __declspec(dllexport) IParser* __stdcall getParserInstance()
    {
        IParser* result = new CircleParser();
        return result;
    }

    __declspec(dllexport) IShapeToStringDataConverter* __stdcall getConverterInstance()
    {
        IShapeToStringDataConverter* result = new CircleToStringConverter();
        return result;
    }
}