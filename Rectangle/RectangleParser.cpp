#include "pch.h"
#include "RectangleParser.h"

RectangleParser* RectangleParser::getInstance()
{
    if (_instance == nullptr) {
        _instance = new RectangleParser();
    }

    return _instance;
}


IShape* RectangleParser::parse(string line)
{
    double width = 0;
    double height = 0;
    regex pattern(".*[W,w]=[0-9]+[.]?[0-9]*,[ ]*[H,h]=[0-9]+[.]?[0-9]*");

    if (line.empty()) {
        throw new NoDataException("Rectangle empty line");
    }

    if (!regex_match(line, pattern)) {
        throw new IncorrectFormat(line.c_str());
    }

    vector<double> values = extractDouble(line);

    if (values.empty() || values.size() != 2) {
        throw new NoDataException("Rectangle missing value");
    }

    if (validate(values) == false) {
        throw new InvalidDataRange(line.c_str());
    }

    width = values[0];
    height = values[1];

    IShape* shape = new RectangleCLS(width, height);
    return shape;
}

string RectangleParser::toString()
{
    return string("RectangleParser");
}

