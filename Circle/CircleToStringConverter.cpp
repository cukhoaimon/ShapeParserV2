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
    // Cast a shape to a circle
    Circle* circle = dynamic_cast<Circle*>(shape);

    // Define a pointer of stream for more flexible
    wstringstream *builder = new wstringstream();

    // Build radius attribute
    *builder << L"Bán kính=" << circle->radius();
    wstring attributes(builder->str());


    // Build shape name attribute
    wstring shapeName = L"Hình tròn";
    
    // delete previous data and allocate another stream.
    delete builder; 
    builder = new wstringstream();

    // Builde perimeter of circle
    *builder << m_round(circle->perimeter(), 1);
    wstring perimeter(builder->str());


    // delete previous data and allocate another stream.
    delete builder;
    builder = new wstringstream();

    // Builde area of circle
    *builder << m_round(circle->area(), 2);
    wstring area = builder->str();

    // return 
    SHAPECONTAINER result = { shapeName, attributes, perimeter, area };
    return result;
}

std::string CircleToStringConverter::toString()
{
    return std::string("CircleToStringConverter");
}

