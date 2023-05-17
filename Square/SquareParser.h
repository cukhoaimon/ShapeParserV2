#pragma once
#include "pch.h"

extern "C" {
    class SquareParser :
        public IParser
    {
    private:
        inline static SquareParser* _instance = nullptr;

        // "= delete" make this method inaccessible 
        // even from from context that can see private 
        // method (like friend class, other method 
        // within class.
        SquareParser(const SquareParser&) = delete;
        SquareParser& operator=(const SquareParser&) = delete;

    protected:
        SquareParser() {};

    public:
        static SquareParser* getInstance();
        IShape* parse(string) override;
        string toString();
    };
}