#include "pch.h"
#include "Triangle.h"


Triangle::Triangle() : _a(0), _b(0), _c(0) {};

Triangle::Triangle(double a, double b, double c)
	: _a(a), _b(b), _c(c) 
{
    if (triangle_validate(a, b, c) == false) {
        throw new InvalidDataRange("The Input parameters of Triangle cannot be a Triangle");
    }
};


double Triangle::area()
{
	double p = perimeter() / 2;
	double result = sqrt(p * (p - _a) * (p - _b) * (p - _c));

	return result;
}

double Triangle::perimeter()
{
	double result = _a + _b + _c;
	return result;
}

string Triangle::toString()
{
	return string("Triangle");
}

bool triangle_validate(double a, double b, double c)
{
    bool result;

    if (a + b > c && a + c > b && b + c > a) {
        result = true;
    }
    else {
        result = false;
    }

    return result;
}