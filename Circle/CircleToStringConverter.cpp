#include "pch.h"
#include "CircleToStringConverter.h"

wstring CircleToStringConverter::convert(IShape* shape)
{
    Circle* circle = (Circle*)shape;
    wstringstream attributesBuilder;
    attributesBuilder << L"Bán kính=" << circle->radius();

    wstring attributes = attributesBuilder.str();


    wstring result = pattern(L"Hình tròn", attributes, circle->perimeter(), circle->perimeter());
    return result;
}

std::string CircleToStringConverter::toString()
{
    return std::string("CircleToStringConverter");
}

