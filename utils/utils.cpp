// utils.cpp : Defines the functions for the static library.

//
#include "pch.h"
#include "utils.h"

vector<double> extractDouble(string line)
{
    double value = 0.0;
    vector<double> values;
    stringstream stream(line);

    // while reader buffer is available
    while (stream.rdbuf()->in_avail()) {
        // get the value
        stream >> value;

        // if reader is good or end of file then push to result
        if (stream.good() || stream.eof()) {
            values.push_back(value);
        }
        else if (stream.bad()) {
            break;
        }
        else if (stream.fail()) {
            stream.clear();
            stream.rdbuf()->sbumpc();
        }
    }

    return values;
}

double m_round(double source, int digits)
{
    source *= source * pow(10, digits);
    source = round(source);
    source /= pow(10, digits);
    return source;
}

wstring getFileName(string dir_path) {

    string file_name = dir_path.substr(dir_path.find_last_of("/\\") + 1);
    wstring result;
    result.assign(file_name.begin(), file_name.end());

    return result;
}

vector<wstring> extractDLLFiles(fs::path src_path)
{
    vector<wstring> result = vector<wstring>();

    regex pattern(".*api-shape-.*\.dll");
    for (auto const& dir_entry : fs::recursive_directory_iterator{ src_path })
    {
        // dir_path use to check the pattern of dll file
        string dir_path(dir_entry.path().string());
        
        if (regex_match(dir_path, pattern)) {
            result.push_back(getFileName(dir_path));
        }
    }

    return result;
}
string extractExtension(wstring src) {
    size_t dash_position = src.find_last_of(TEXT('-'));
    size_t dot_position = src.find_last_of(TEXT('.'));
    
    wstring r_result = src.substr(dash_position + 1, dot_position - dash_position - 1);
    
    string result(r_result.begin(), r_result.end());
    return result;
}

Width getWidth(vector<SHAPECONTAINER> contaiers)
{
    Width result = {0,0,0,0};

    for (SHAPECONTAINER container : contaiers) {
        const auto& [shapeName, shapeDescription, perimeter, area] = container;

        if (static_cast<int>(shapeName.size()) > result.shape_name) {
            result.shape_name = shapeName.size();
        }

        if (static_cast<int>(shapeDescription.size()) > result.shape_descriptions) {
            result.shape_descriptions = shapeDescription.size();
        }

        if (static_cast<int>(perimeter.size()) > result.shape_perimeter) {
            result.shape_perimeter = perimeter.size();
        }

        if (static_cast<int>(area.size()) > result.shape_area) {
            result.shape_area = area.size();
        }
    }

    return Width(result);
}

bool byArea(SHAPECONTAINER a, SHAPECONTAINER b)
{
    double area_a = stod(get<3>(a));
    double area_b = stod(get<3>(b));

    bool result = area_a < area_b;
    return result;
}


bool validate(vector<double> values)
{
    bool result = true;
    
    for (double value : values) {
        result = result && (value > 0);
    }

    return result;
}