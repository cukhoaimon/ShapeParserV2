#include "ShapePrinter.h"

wstring ShapePrinter::pattern(TUPLEOFSHAPESTRING tup)
{
	const auto& [shapeName, shapeDescription, perimeter, area] = tup;

    wstringstream builder;

    builder << " | ";
    builder.fill(' ');
    builder.width(15);
    builder << left << shapeName;

    // column 3
    builder << " | ";
    builder.fill(' ');
    builder.width(20);
    builder << left << shapeDescription;

    // column 4
    builder << " | ";
    builder << left << L"Chu vi=" << left;
    builder.fill(' ');
    builder.width(10);
    builder << perimeter;

    // column 5
    builder << " | ";
    builder << left << L"Diện tích=" <<  left;
    builder.fill(' ');
    builder.width(10);
    builder << area;
    builder << " |";

    wstring result = builder.str();
    return result;
}

ShapePrinter::ShapePrinter()
{
    _holder = vector<TUPLEOFSHAPESTRING>();
}

void ShapePrinter::push(TUPLEOFSHAPESTRING element)
{
    _holder.push_back(element);
}

void ShapePrinter::clear()
{
    _holder.clear();
}

void ShapePrinter::print()
{
    int index = 1;
    for (const auto& shape : _holder) {
        wcout << "| " << index << pattern(shape) << endl;
        index += 1;
    }
}
