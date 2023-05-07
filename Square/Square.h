#ifndef SQUARE_H
#define SQUARE_H

#include "pch.h"

extern "C" {
    class Square :
        public IShape
    {
    private:
        double _width;

    public:
        Square();
        Square(double);

    public:
        double width();
        double perimeter();
        double area();

    public:
        string toString();
    };
}

#endif // !SQUARE_H

