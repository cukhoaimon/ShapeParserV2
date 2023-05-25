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

namespace fs = std::filesystem;


typedef tuple<wstring, wstring, wstring, wstring> TUPLEOFSHAPESTRING;

vector<double> extractDouble(string line);
wstring getFileName(string);
vector<wstring> extractDLLFiles(fs::path);
string extractExtension(wstring);
