#pragma once

#include "pch.h"
#include "Circle.h"


extern "C" {
    class CircleParser :
        public IParser
    {
    private:
        inline static CircleParser* _instance = nullptr;
        CircleParser();

    public:
        static CircleParser* getInstance();
        IShape* parse(string);
    };
}