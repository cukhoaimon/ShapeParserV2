#pragma once

#include "pch.h"
#include "Circle.h"


extern "C" {
    class CircleToStringConverter :
        public IShapeToStringDataConverter
    {
    private:
        inline static CircleToStringConverter* _instance = nullptr;
        CircleToStringConverter();

    public:
        /// <summary>
        /// Get instance of Circle Parser
        /// </summary>
        /// <returns>an singleton instance</returns>
        static CircleToStringConverter* getInstance();

        /// <summary>
        /// Convert a Shape into SHAPECONTAINER which known as 
        /// a tuple of shape information
        /// </summary>
        /// <param name="IShape">Data of shape</param>
        /// <returns>a tuple of shape information</returns>
        SHAPECONTAINER convert(IShape*);
        string toString();
    };
}
