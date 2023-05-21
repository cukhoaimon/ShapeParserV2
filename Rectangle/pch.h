	// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that pre-compile 
#include "framework.h"

// include shape component
#include "..\ShapeParserV2\Model\IShape.h"
#include "..\ShapeParserV2\Controller\IShapeToStringDataConverter.h"
#include "..\ShapeParserV2\Controller\IParser.h"

// include dependencies
#include "..\utils\utils.h"
#include "..\Exception\Exception.h"

class Rectangle;

#endif //PCH_H
