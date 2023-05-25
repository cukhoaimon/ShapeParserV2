#pragma once
// utils.h : Defines the functions for the static library.
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
#include <algorithm> // use for std::sort
#include <exception>

class IShape; // forward declairation

// API type
#define SHAPE_API __declspec(dllexport) 

// define a method to convert string to wstring
#define W_STR(file_name) wstring(file_name.begin(), file_name.end())

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
using std::shared_ptr, std::make_shared;
using std::unique_ptr, std::move;
using std::sort;
using std::exception;

namespace fs = std::filesystem;

/// <summary>
/// A tuple with 4 wstring include:
/// 1. Shape name
/// 2. Shape description
/// 3. Shape perimeter
/// 4. Shape area
/// </summary>
typedef tuple<wstring, wstring, wstring, wstring> SHAPECONTAINER;

/// <summary>
/// A struct for setting width for each column
/// </summary>
struct Width {
	int shape_name;
	int shape_descriptions;
	int shape_perimeter;
	int shape_area;
};


/// <summary>
/// Extract a list of double from a string line
/// </summary>
/// <param name="line">source data</param>
/// <returns>vector of double value</returns>
vector<double> extractDouble(string line);

/// <summary>
/// Round double value with n-digits
/// </summary>
/// <param name="value">source value to round</param>
/// <param name="digits">number of digits</param>
/// <returns>value after round</returns>
double m_round(double value, int digits);

/// <summary>
/// Get file name from a directory
/// </summary>
/// <param name="dir_path">directory</param>
/// <returns>file name</returns>
wstring getFileName(string dir_path);

/// <summary>
/// Get name of all DLL file containt in project
/// </summary>
/// <param name="src_path">filesystem path</param>
/// <returns>vector of DLL file</returns>
vector<wstring> extractDLLFiles(fs::path src_path);


/// <summary>
/// extract file name without extension from a wstring
/// Example:
/// - Input: shape.dll
/// - Output: shape
/// </summary>
/// <param name="src">source wstring</param>
/// <returns>file name</returns>
string extractExtension(wstring src);

/// <summary>
/// Calculate the maximum width for each field
/// </summary>
/// <param name="containers">converted data</param>
/// <returns>Struct holding the needed width for each field</returns>
Width getWidth(vector<SHAPECONTAINER> containers);


/// <summary> 
/// Subfunction use for std::sort.
/// A criteria that show std::sort know that
/// we are sorting ascending by shape area.
/// </summary>
/// <returns>True/false</returns>
bool byArea(SHAPECONTAINER a, SHAPECONTAINER b);



/// <summary>
/// Check for values is valid or not
/// </summary>
/// <returns>True if all value is valid</returns>
bool validate(vector<double> values);



