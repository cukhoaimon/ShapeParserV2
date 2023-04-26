#include "pch.h"
#include "CircleParser.h"

IShape* CircleParser::parse(string line)
{
    double radius = 0;
    regex pattern(".*[R,r]=[0-9]+[.]?[0-9]*");

    if (regex_match(line, pattern)) {
        radius = extractDouble(line)[0];
    }

    IShape* shape = new Circle(radius);
    return shape;
}

