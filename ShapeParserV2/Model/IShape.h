#pragma once
#include <string>

class IShape 
{
public:
    virtual double perimeter() = 0;
    virtual double area() = 0;
    virtual std::string toString() = 0;
};

