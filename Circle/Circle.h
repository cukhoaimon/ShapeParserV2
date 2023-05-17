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
        double area() override;
        double perimeter() override;

        string toString();
    }; 
}

