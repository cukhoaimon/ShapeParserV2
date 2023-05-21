// Exception.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "Exception.h"

const char* NoDataException::what() const throw()
{
    stringstream builder;
    builder << "[!] No Data Exception." << endl;
    builder << "\t+ Exception cause when parsing string to shape" << endl;
    builder << "\t+ Detail: [" << string(message) << "]" << endl;

    const char* result = COPY_STREAM(builder);
    return result;
}


const char* IncorrectFormat::what() const throw()
{
    stringstream builder;
    builder << "[!] Incorrect format." << endl;
    builder << "\t+ Exception cause when parsing string to shape" << endl;
    builder << "\t+ Detail: [" << string(message) << "]" << endl;

    const char* result = COPY_STREAM(builder);
    return result;
}
