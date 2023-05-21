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

    if (!regex_match(line, pattern)) {
        throw new IncorrectFormat(line.c_str());
    }

    vector<double> values = extractDouble(line);

    if (values.empty()) {
        throw new NoDataException("Circle");
    }


    if (validate(values) == false) {
        throw new InvalidDataRange(line.c_str());
    }

    radius = values[0];

    IShape* shape = new Circle(radius);
    return shape;
}

string CircleParser::toString()
{
    return string("CircleParser");
}

