#pragma once
#include "..\Model\IShape.h"

class IParser
{
public:
    virtual IShape* parse (std::string) = 0;
};

