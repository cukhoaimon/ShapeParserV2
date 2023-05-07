#pragma once
#include "pch.h"

class Rectangle :
    public IShape
{
private:
    double _width;
    double _height;

public:
    Rectangle(double, double);

    double width();
    double height();
    double perimeter();
    double area();

    string toString();
};

