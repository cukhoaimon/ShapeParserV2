#pragma once
#include <string>
#include "..\Object.h"

class IShape : public Object
{
public:
    virtual double perimeter() = 0;
    virtual double area() = 0;
};

