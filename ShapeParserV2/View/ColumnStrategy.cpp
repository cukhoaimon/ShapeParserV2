#include "ColumnStrategy.h"


ColumnStrategy* ColumnStrategy::getInstance()
{
    if (_instance == nullptr) {
        _instance = new ColumnStrategy();
    }

    return _instance;
}

void ColumnStrategy::execute(vector<SHAPECONTAINER> containers, string file_name, int expected)
{
    Width width = getWidth(containers);

    int count = 1;
    for (auto& container : containers) {
        const auto& [shapeName, shapeDescription, perimeter, area] = container;

        wstringstream builder;

        // cột 1
        builder << "| " << count;
        count++;

        // cột 2
        builder << " | ";
        builder.fill(' ');
        builder.width(static_cast<std::streamsize>(width.shape_name));
        builder << left << shapeName;

        // cột 3
        builder << " | ";
        builder.fill(' ');
        builder.width(static_cast<std::streamsize>(width.shape_descriptions));
        builder << left << shapeDescription;

        // cột 4
        builder << " | ";
        builder << left << L"Chu vi=" << left;
        builder.fill(' ');
        builder.width(static_cast<std::streamsize>(width.shape_perimeter));
        builder << perimeter;

        // cột 5
        builder << " | ";
        builder << left << L"Diện tích=" << left;
        builder.fill(' ');
        builder.width(static_cast<std::streamsize>(width.shape_area));
        builder << area;
        builder << " |";

        // in ra màn hình
        wcout << builder.str() << endl;
    }
}

string ColumnStrategy::toString()
{
	return string("ColumnStrategy");
}