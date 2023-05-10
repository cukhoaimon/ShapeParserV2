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
        ~Circle() {
            wcout << L"Cirlce bị thu hồi rồi đụ mẹ mày nhá " << endl;
        }

        double radius();
        double area() override;
        double perimeter() override;

        string toString();
    }; 
}

