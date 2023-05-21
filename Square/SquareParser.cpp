#include "pch.h"
#include "SquareParser.h"
#include "Square.h"

SquareParser* SquareParser::getInstance()
{
    if (_instance == nullptr) {
        _instance = new SquareParser();
    }

    return _instance;
}

IShape* SquareParser::parse(string line)
{
    double width = 0;
    regex pattern(".*[A,a]=[0-9]*[.]?[0-9]*");

    if (line.empty()) {
        throw new NoDataException("Square");
    }

    if (!regex_match(line, pattern)) {
        throw new IncorrectFormat(line.c_str());
    }

    vector<double> values = extractDouble(line);

    if (values.empty()) {
        throw new NoDataException("Square");
    }

    if (validate(values) == false) {
        throw new InvalidDataRange(line.c_str());
    }

    width = values[0];
    IShape* shape = new Square(width);
    return shape;
}

string SquareParser::toString()
{
    return string("SquareParser");
}
