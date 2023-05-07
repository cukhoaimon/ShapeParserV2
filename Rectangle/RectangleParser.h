#pragma once
#include "pch.h"

class RectangleParser :
    public IParser
{
public:
    IShape* parse(string);
};

#include "RectangleParser.h"

IShape* RectangleParser::parse(string line)
{
    double width = 0;
    double height = 0;
    regex pattern(".*[W,w]=[0-9]*[.]?[0-9]*, [H,h]=[0-9]+[.]?[0-9]*");

    if (regex_match(line, pattern)) {
        vector<double> values = extractDouble(line);
        width = values[0];
        height = values[1];
    }

    IShape* shape = new Rectangle(width, height);
    return shape;
}
