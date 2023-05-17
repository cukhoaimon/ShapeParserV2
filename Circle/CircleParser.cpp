#include "pch.h"
#include "CircleParser.h"

CircleParser* CircleParser::getInstance()
{
    if (_instance == nullptr) {
        _instance = new CircleParser();
    }

    return _instance;
}


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

string CircleParser::toString()
{
    return string("CircleParser");
}

