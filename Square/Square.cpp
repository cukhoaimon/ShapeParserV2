#include "pch.h"
#include "Square.h"

Square::Square() : _width(0) {};

Square::Square(double width) : _width(width) {}

double Square::width()
{
	return _width;
}

double Square::perimeter()
{
	double result = _width * 4;
	return result;
}

double Square::area()
{
	double result = _width * _width;
	return result ;
}

string Square::toString()
{
	return string("Square");
}

