#pragma once

#include "pch.h"
#include "Triangle.h"

extern "C" {
    class TriangleParser :
        public IParser
    {
    private:
        inline static TriangleParser* _instance = nullptr;

        // "= delete" make this method inaccessible 
        // even from from context that can see private 
        // method (like friend class, other method 
        // within class.
        TriangleParser(const TriangleParser&) = delete;
        TriangleParser& operator=(const TriangleParser&) = delete;


    protected:
        TriangleParser() {};

    public:
        static TriangleParser* getInstance();
        IShape* parse(string) override;
        string toString();
    };
}