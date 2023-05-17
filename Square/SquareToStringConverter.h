#pragma once
#include "pch.h"
#include "Square.h"

extern "C" {
    class SquareToStringConverter
        : public IShapeToStringDataConverter
    {
    private:
        inline static SquareToStringConverter* _instance = nullptr;

        // "= delete" make this method inaccessible 
        // even from from context that can see private 
        // method (like friend class, other method 
        // within class.
        SquareToStringConverter(const SquareToStringConverter&) = delete;
        SquareToStringConverter& operator=(const SquareToStringConverter&) = delete;

    protected:
        SquareToStringConverter() {};

    public:
        static SquareToStringConverter* getInstance();
        SHAPECONTAINER convert(IShape*);
        string toString();
    };
}