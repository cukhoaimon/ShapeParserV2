// utils.cpp : Defines the functions for the static library.

//
#include "pch.h"
#include "utils.h"

vector<double> extractDouble(string line)
{
    double value = 0.0;
    vector<double> values;
    stringstream stream(line);

    while (stream.rdbuf()->in_avail()) {
        stream >> value;

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

    regex pattern(".*.dll");
    for (auto const& dir_entry : fs::recursive_directory_iterator{ src_path })
    {
        string dir_path{ dir_entry.path().string() };

        if (regex_match(dir_path, pattern)) {

            result.push_back(getFileName(dir_path));
        }
    }

    return result;
}
string extractExtension(wstring src) {
    wstring r_result = src.substr(0, src.find_last_of(TEXT('.')));
    string result(r_result.begin(), r_result.end());

    return result;
}