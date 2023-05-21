#pragma once

#include "framework.h"
#include "pch.h"

#include <exception>
#include <sstream>
#include <string>
#include <Windows.h>

// Convert and allocate memory from a stream to const char*
#define COPY_STREAM(stream) _strdup(stream.str().c_str())

using std::exception;
using std::string, std::stringstream;
using std::endl;


class NoDataException 
	: public exception 
{
private: 
	const char* message;

public:
	NoDataException(const char* msg) : message(_strdup(msg)) {};
	~NoDataException() { delete[] message; };

	const char* what() const throw();
};


class IncorrectFormat
	: public exception
{
private:
	const char* message;

public:
	IncorrectFormat(const char* msg) : message(_strdup(msg)) {};
	~IncorrectFormat() { delete[] message; };

	const char* what() const throw();
};