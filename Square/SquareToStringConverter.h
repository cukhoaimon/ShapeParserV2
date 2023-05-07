#pragma once
#include "pch.h"
#include "Square.h"

extern "C" {
    class SquareToStringConverter
        : public IShapeToStringDataConverter
    {
    private:
        inline static SquareToStringConverter* _instance = nullptr;
        SquareToStringConverter();

    public:
        static SquareToStringConverter* getInstance();
        TUPLEOFSHAPESTRING convert(IShape*);
        string toString();
    };
}