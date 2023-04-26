#pragma once

#include "pch.h"
#include "Circle.h"


extern "C" {
    class CircleToStringConverter :
        public IShapeToStringDataConverter
    {
    public:
        std::wstring convert(IShape*);
        std::string toString();
    };
}
