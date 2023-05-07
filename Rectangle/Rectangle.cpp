#include "pch.h"
#include "Rectangle.h"

Rectangle::Rectangle(double width, double height)
{
	_width = width;
	_height = height;
}

double Rectangle::width()
{
	return _width;
}

double Rectangle::height()
{
	return _height;
}

double Rectangle::perimeter()
{
	double result = (_width + _height) * 2;
	return result;
}

double Rectangle::area()
{
	double result = _width * _height;
	return result;
}

string Rectangle::toString()
{
	return string("Rectangle");
}