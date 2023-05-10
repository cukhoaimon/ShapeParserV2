#include "pch.h"
#include "CircleToStringConverter.h"

CircleToStringConverter::CircleToStringConverter() {
    // do nothing
}

CircleToStringConverter* CircleToStringConverter::getInstance()
{
    if (_instance == nullptr) {
        _instance = new CircleToStringConverter();
    }

    return _instance;
}

SHAPECONTAINER CircleToStringConverter::convert(IShape* shape)
{
    Circle* circle = (Circle*)shape;
    wstringstream *builder = new wstringstream;

    *builder << L"Bán kính=" << circle->radius();
    wstring attributes(builder->str());

    wstring shapeName = L"Hình tròn";
    
    delete builder;
    builder = new wstringstream;
    *builder << m_round(circle->perimeter(), 1);
    wstring perimeter(builder->str());

    delete builder;
    builder = new wstringstream;
    *builder << m_round(circle->area(), 2);
    wstring area = builder->str();

    SHAPECONTAINER result = { shapeName, attributes, perimeter, area };
    return result;
}

std::string CircleToStringConverter::toString()
{
    return std::string("CircleToStringConverter");
}

