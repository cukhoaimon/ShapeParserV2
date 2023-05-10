#include "DetailStrategy.h"

DetailStrategy::DetailStrategy() {
	// do nothing
}

DetailStrategy* DetailStrategy::getInstance()
{
	if (_instance == nullptr) {
		_instance = new DetailStrategy();
	}

	return _instance;
}

void DetailStrategy::execute(vector<SHAPECONTAINER> container, string file_name, int expected)
{
	wcout << L"Đang đọc tập tin " << W_STR(file_name) << "..." << endl;
	wcout << L"Tìm thấy " << expected << L" hình" << endl;

	int i = 1;
	for (auto& shape : container) {
		const auto& [shapeName, shapeDescription, perimeter, area] = shape;

		wcout << i << ". " << shapeName << ": " << shapeDescription << endl;
		i += 1;
	}
}

string DetailStrategy::toString()
{
	return string("DetailStrategy");
}
