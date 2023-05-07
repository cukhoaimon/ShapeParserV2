#include "pch.h"
#include "SquareToStringConverter.h"
#include "Square.h"

SquareToStringConverter::SquareToStringConverter() {

}

SquareToStringConverter* SquareToStringConverter::getInstance()
{
    if (_instance == nullptr) {
        _instance = new SquareToStringConverter();
    }
    return _instance;
}

TUPLEOFSHAPESTRING SquareToStringConverter::convert(IShape* shape)
{
    Square* square = (Square*)shape;
    wstringstream* builder = new wstringstream;

    *builder << L"Cạnh=" << square->width();
    wstring attributes(builder->str());

    wstring shapeName = L"Hình vuông";

    delete builder;
    builder = new wstringstream;
    *builder << m_round(square->perimeter(), 1);
    wstring perimeter(builder->str());

    delete builder;
    builder = new wstringstream;
    *builder << m_round(square->area(), 2);
    wstring area = builder->str();

    TUPLEOFSHAPESTRING result = { shapeName, attributes, perimeter, area };
    return result;
}

string SquareToStringConverter::toString()
{
    return string("SquareToStringConverter");
}