#pragma once

#include "pch.h"

extern "C" {
    class Circle :
        public IShape
    {
    private:
        double _radius;

    public:

        Circle();
        Circle(double radius);

        double radius();
        double area();
        double perimeter();

        string toString();
    }; 
}

