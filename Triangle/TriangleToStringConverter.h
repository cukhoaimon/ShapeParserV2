#pragma once

#include "pch.h"
#include "Triangle.h"


extern "C" {
    class TriangleToStringConverter :
        public IShapeToStringDataConverter
    {
    private:
        inline static TriangleToStringConverter* _instance = nullptr;
        TriangleToStringConverter() {};

    public:
        /// <summary>
        /// Get instance of Triangle Parser
        /// </summary>
        /// <returns>an singleton instance</returns>
        static TriangleToStringConverter* getInstance();

        /// <summary>
        /// Convert a Shape into SHAPECONTAINER which known as 
        /// a tuple of shape information
        /// </summary>
        /// <param name="shape">Data of shape</param>
        /// <returns>a tuple of shape information</returns>
        SHAPECONTAINER convert(IShape* shape);
        string toString();
    };
}
