#include "LoadingFailStrategy.h"

LoadingFailStrategy::LoadingFailStrategy() {
	// do nothing
}

LoadingFailStrategy* LoadingFailStrategy::getInstance()
{
	if (nullptr == _instance) {
		_instance = new LoadingFailStrategy();
	}

	return _instance;
}

void LoadingFailStrategy::execute(vector<SHAPECONTAINER> container, string file_name, int expected)
{
	int found = container.size();
	int loss = expected - found;
	wcout << L"Đang đọc tập tin " << W_STR(file_name) << "..." << endl;
	wcout << L"Tìm thấy " << found << L" hình / " << expected << L" hình" << endl;

	int i = 1;
	for (auto& shape : container) {
		const auto& [shapeName, shapeDescription, perimeter, area] = shape;

		wcout << i << ". " << shapeName << ": " << shapeDescription << endl;
		i += 1;
	}

	wcout << L"Không thể đọc được: " << loss << L" hình." << endl;
}

string LoadingFailStrategy::toString()
{
	return string("LoadingFailStrategy");
}
