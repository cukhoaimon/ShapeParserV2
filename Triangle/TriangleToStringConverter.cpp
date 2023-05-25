#include "pch.h"
#include "TriangleToStringConverter.h"
#include "Triangle.h"

TriangleToStringConverter* TriangleToStringConverter::getInstance()
{
    if (_instance == nullptr) {
        _instance = new TriangleToStringConverter();
    }

    return _instance;
}

SHAPECONTAINER TriangleToStringConverter::convert(IShape* shape)
{
    // Cast a shape to a circle
    Triangle* rectangle = dynamic_cast<Triangle*>(shape);

    // Define a pointer of stream for more flexible
    wstringstream* builder = new wstringstream();

    // Build radius attribute
    *builder << L"a=" << rectangle->a() << ", ";
    *builder << L"b=" << rectangle->b() << ", ";
    *builder << L"c=" << rectangle->c();
    wstring attributes(builder->str());

    // Build shape name attribute
    wstring shapeName = L"Hình tam giác";

    // delete previous data and allocate another stream.
    delete builder;
    builder = new wstringstream();

    // Builde perimeter of circle
    *builder << m_round(rectangle->perimeter(), 1);
    wstring perimeter(builder->str());


    // delete previous data and allocate another stream.
    delete builder;
    builder = new wstringstream();

    // Builde area of circle
    *builder << m_round(rectangle->area(), 2);
    wstring area = builder->str();

    // return 
    SHAPECONTAINER result = { shapeName, attributes, perimeter, area };
    return result;
}

string TriangleToStringConverter::toString()
{
    return string("TriangleToStringConverter");
}

