#pragma once
#include "..\Controller\IParser.h"
#include <map>
#include <string>

using std::map, std::string;

class ShapeFactory
{
private:
    map<string, IParser*> _prototypes;

public:
    void registerWith(string, IParser*);

public:
    IParser* select(string);

public:
    string toString();
};