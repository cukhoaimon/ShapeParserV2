#pragma once

#include "pch.h"
#include "Circle.h"


extern "C" {
    class CircleParser :
        public IParser
    {
    private:
        inline static CircleParser* _instance = nullptr;

        // "= delete" make this method inaccessible 
        // even from from context that can see private 
        // method (like friend class, other method 
        // within class.
        CircleParser(const CircleParser&) = delete;
        CircleParser& operator=(const CircleParser&) = delete;


    protected:
        CircleParser() {};

    public:
        static CircleParser* getInstance();
        IShape* parse(string) override;
        string toString();
    };
}