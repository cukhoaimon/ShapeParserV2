#pragma once
#include "pch.h"


extern "C" {
    class Triangle :
        public IShape
    {
    private:
        double _a;
        double _b;
        double _c;

    public:
        Triangle();
        Triangle(double a, double b, double c);

        double a() { return _a; };
        double b() { return _b; };
        double c() { return _c; };

        double area() override;
        double perimeter() override;

        string toString();
    };
}

/// <summary>
/// A local function just for triangle. 
/// Use for validating input parameters
/// can be a triangle or not
/// </summary>
/// <returns>True if parameters are valid, otherwise return False</returns>
bool triangle_validate(double a, double b, double c);