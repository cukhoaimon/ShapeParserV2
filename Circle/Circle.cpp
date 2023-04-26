#include "pch.h"
#include "Circle.h"

Circle::Circle() : _radius(0.0) {};

Circle::Circle(double radius) : _radius(radius) {};

double Circle::radius()
{
    return _radius;
}

double Circle::perimeter()
{
    double result = 2 * _radius * std::numbers::pi;
    return result;
}

double Circle::area()
{
    double result = _radius * _radius * std::numbers::pi;
    return result;
}

string Circle::toString()
{
    return string("Circle");
}
