#pragma once
// utils.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"

#include <iostream>
#include <string>
#include <sstream>
#include <numbers> // std::number::pi
#include <regex>
#include <vector>
#include <map>
#include <fstream>
#include <io.h>    // use for _setmode to printout unicode character
#include <fcntl.h> // use for _O_U16TEXT mode
#include <iomanip>
#include <filesystem>
#include <windows.h> 
#include <tuple>
#include <memory>

#define SHAPE_API __declspec(dllexport) 


using std::cout, std::cin, std::endl;
using std::wcout;
using std::string, std::wstring;
using std::stringstream, std::wstringstream;
using std::regex, std::regex_match;
using std::vector;
using std::map;
using std::ifstream, std::ofstream;
using std::setw, std::left, std::setprecision, std::fixed;
using std::tuple;
using std::shared_ptr;

namespace fs = std::filesystem;

typedef tuple<wstring, wstring, wstring, wstring> TUPLEOFSHAPESTRING;

vector<double> extractDouble(string line);

double m_round(double, int);

wstring getFileName(string dir_path);

vector<wstring> extractDLLFiles(fs::path src_path);

string extractExtension(wstring src);
