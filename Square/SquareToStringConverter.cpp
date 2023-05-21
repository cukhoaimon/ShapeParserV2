#include "pch.h"
#include "SquareToStringConverter.h"
#include "Square.h"


SquareToStringConverter* SquareToStringConverter::getInstance()
{
    if (_instance == nullptr) {
        _instance = new SquareToStringConverter();
    }
    return _instance;
}

SHAPECONTAINER SquareToStringConverter::convert(IShape* shape)
{
    // Cast a shape to square
    Square* square = dynamic_cast<Square*>(shape);

    // Define a pointer of stream for more flexible
    wstringstream* builder = new wstringstream();

    // Build radius attribute
    *builder << L"Cạnh=" << square->width();
    wstring attributes(builder->str());

    // Build shape name attribute
    wstring shapeName = L"Hình vuông";

    // delete previous data and allocate another stream.
    delete builder;
    builder = new wstringstream();

    // Builde perimeter of circle
    *builder << m_round(square->perimeter(), 1);
    wstring perimeter(builder->str());

    // delete previous data and allocate another stream.
    delete builder;
    builder = new wstringstream();

    // Builde area of circle
    *builder << m_round(square->area(), 2);
    wstring area = builder->str();

    // return 
    SHAPECONTAINER result = { shapeName, attributes, perimeter, area };
    return result;
}

string SquareToStringConverter::toString()
{
    return string("SquareToStringConverter");
}