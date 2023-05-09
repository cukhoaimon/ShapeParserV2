#pragma once
#include "pch.h"

extern "C" {
    class SquareParser :
        public IParser
    {
    private:
        inline static SquareParser* _instance = nullptr;
        SquareParser();

    public:
        static SquareParser* getInstance();
        IShape* parse(string) override;
        string toString();
    };
}