#pragma once

#include "pch.h"
#include "Rectangle.h"


extern "C" {
    class RectangleToStringConverter :
        public IShapeToStringDataConverter
    {
    private:
        inline static RectangleToStringConverter* _instance = nullptr;
        RectangleToStringConverter() {};

    public:
        /// <summary>
        /// Get instance of Rectangle Parser
        /// </summary>
        /// <returns>an singleton instance</returns>
        static RectangleToStringConverter* getInstance();

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
