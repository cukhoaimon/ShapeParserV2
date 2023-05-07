#include "pch.h"
#include "SquareParser.h"

#include "Square.h"

SquareParser::SquareParser() {
    // do nothing
}

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

    if (regex_match(line, pattern)) {
        vector<double> values = extractDouble(line);
        width = values[0];
    }

    IShape* shape = new Square(width);
    return shape;
}