#pragma once
#include "pch.h"


extern "C" {
    class RectangleCLS :
        public IShape
    {
    private:
        double _width;
        double _height;

    public:
        RectangleCLS();
        RectangleCLS(double width, double height);

        double width() { return _width; };
        double height() { return _height; };

        double area() override;
        double perimeter() override;

        string toString();
    };
}