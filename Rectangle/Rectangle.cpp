#include "pch.h"
#include "Rectangle.h"


RectangleCLS::RectangleCLS()
{
	this->_width = 0;
	this->_height = 0;
};

RectangleCLS::RectangleCLS(double width, double height)
{
	this->_width = width;
	this->_height = height;
};

double RectangleCLS::area()
{
	double result = _width * _height;
	return result;
}

double RectangleCLS::perimeter()
{
	double result = 2 * (_width + _height);
	return result;
}

string RectangleCLS::toString()
{
	return string("Rectangle");
}
