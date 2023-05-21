#pragma once

#include "pch.h"
#include "Rectangle.h"

extern "C" {
    class RectangleParser :
        public IParser
    {
    private:
        inline static RectangleParser* _instance = nullptr;

        // "= delete" make this method inaccessible 
        // even from from context that can see private 
        // method (like friend class, other method 
        // within class.
        RectangleParser(const RectangleParser&) = delete;
        RectangleParser& operator=(const RectangleParser&) = delete;


    protected:
        RectangleParser() {};

    public:
        static RectangleParser* getInstance();
        IShape* parse(string) override;
        string toString();
    };
}