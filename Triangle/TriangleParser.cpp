#include "pch.h"
#include "TriangleParser.h"

TriangleParser* TriangleParser::getInstance()
{
    if (_instance == nullptr) {
        _instance = new TriangleParser();
    }

    return _instance;
}


IShape* TriangleParser::parse(string line)
{
    double a = 0;
    double b = 0;
    double c = 0;

    regex pattern(".*[A, a]=[0-9]+[.]?[0-9]*,[ ]*[B, b]=[0-9]+[.]?[0-9]*,[ ]*[C,c]=[0-9]+[.]?[0-9]*");

    if (line.empty()) {
        throw new NoDataException("Triangle empty line");
    }

    if (!regex_match(line, pattern)) {
        throw new IncorrectFormat(line.c_str());
    }

    vector<double> values = extractDouble(line);

    if (values.empty() || values.size() != 3) {
        throw new NoDataException("Triangle missing value");
    }

    if (validate(values) == false) {
        throw new InvalidDataRange(line.c_str());
    }

    a = values[0];
    b = values[1];
    c = values[2];

    IShape* shape = new Triangle(a, b, c);
    return shape;
}

string TriangleParser::toString()
{
    return string("TriangleParser");
}

