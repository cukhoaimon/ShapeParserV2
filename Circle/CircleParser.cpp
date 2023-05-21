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

    if (line.empty()) {
        throw new NoDataException("Circle");
    }

    if (regex_match(line, pattern)) {
        vector<double> values = extractDouble(line);
        radius = values[0];
    }
    else {
        throw new IncorrectFormat(line.c_str());
    }

    IShape* shape = new Circle(radius);
    return shape;
}

string CircleParser::toString()
{
    return string("CircleParser");
}

