#include "pch.h"
#include "RectangleToStringConverter.h"
#include "Rectangle.h"

RectangleToStringConverter* RectangleToStringConverter::getInstance()
{
    if (_instance == nullptr) {
        _instance = new RectangleToStringConverter();
    }

    return _instance;
}

SHAPECONTAINER RectangleToStringConverter::convert(IShape* shape)
{
    // Cast a shape to a circle
    RectangleCLS* rectangle = dynamic_cast<RectangleCLS*>(shape);

    // Define a pointer of stream for more flexible
    wstringstream* builder = new wstringstream();

    // Build radius attribute
    *builder << L"Rộng=" << rectangle->width() << ", ";
    *builder << L"Cao=" << rectangle->height();
    wstring attributes(builder->str());

    // Build shape name attribute
    wstring shapeName = L"Hình chữ nhật";

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

string RectangleToStringConverter::toString()
{
    return string("RectangleToStringConverter");
}

