#include "ColumnStrategy.h"

ColumnStrategy::ColumnStrategy() {
    // do nothing
}

ColumnStrategy* ColumnStrategy::getInstance()
{
    if (_instance == nullptr) {
        _instance = new ColumnStrategy();
    }

    return _instance;
}

void ColumnStrategy::execute(vector<SHAPECONTAINER> containers, string file_name, int expected)
{
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
        builder.width(15);
        builder << left << shapeName;

        // cột 3
        builder << " | ";
        builder.fill(' ');
        builder.width(20);
        builder << left << shapeDescription;

        // cột 4
        builder << " | ";
        builder << left << L"Chu vi=" << left;
        builder.fill(' ');
        builder.width(10);
        builder << perimeter;

        // cột 5
        builder << " | ";
        builder << left << L"Diện tích=" << left;
        builder.fill(' ');
        builder.width(10);
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