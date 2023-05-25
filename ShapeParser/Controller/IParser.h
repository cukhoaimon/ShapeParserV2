#pragma once
#include "..\Model\IShape.h"
#include "..\Object.h"

class IParser : public Object
{
public:
    virtual IShape* parse (std::string) = 0;
};

