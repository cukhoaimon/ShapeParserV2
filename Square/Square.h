#pragma once
#include "pch.h"

extern "C" {
    class Square :
        public IShape
    {
    private:
        double _width;

    public:
        Square();
        Square(double);

    public:
        double width();
        double perimeter();
        double area();

    public:
        string toString();
    };
}

