#include "Model/IShape.h"
#include "Controller/ShapeFactory.h"
#include "Controller/ConverterFactory.h"
#include "View/ShapePrinter.h"
#include "View/ColumnStrategy.h"
#include "View/DetailStrategy.h"
#include "View/LoadingFailStrategy.h"
#include "View/IStrategy.h"
#include "../utils/utils.h"

int main()
{
	// Biến lưu trữ kết quả của setmode 
	// decode utf16 cho việc in ra màn hình
	// tiếng Việt.
	int hr = _setmode(_fileno(stdout), _O_U16TEXT);
	
	// Định nghĩa các con trỏ hàm trỏ đến 
	// hàm khởi tạo instance trong các file DLL
	typedef IParser* (__cdecl* FN_SHAPE_PARSER)();
	typedef IShapeToStringDataConverter* (__cdecl* FN_SHAPE_CONVERTER)();

	// Khởi tạo ban đầu rỗng
	FN_SHAPE_PARSER fn_parser = nullptr;
	FN_SHAPE_CONVERTER fn_converter = nullptr;

	// Khởi tạo các factory cho Converter và Parser
	ConverterFactory c_factory;
	ShapeFactory s_factory;

	// Đọc file DLL và đăng ký với Factory
	const fs::path find_path{ ".." };
	vector<wstring> dll_names = extractDLLFiles(find_path);
	
	// Vector quản lý các file DLL để giải phóng
	// vùng nhớ khi hết chương trình
	vector<HINSTANCE> hinstLibs;
	for (wstring file_name : dll_names) {
		HINSTANCE hinstLib;
		BOOL fRunTimeLinkSuccess = FALSE;

		hinstLib = LoadLibrary(file_name.c_str());

		// Nếu đọc file thành công
		if (hinstLib != NULL)
		{
			fRunTimeLinkSuccess = TRUE;

			fn_parser = (FN_SHAPE_PARSER)GetProcAddress(hinstLib, "getParserInstance");
			fn_converter = (FN_SHAPE_CONVERTER)GetProcAddress(hinstLib, "getConverterInstance");

			if (NULL != fn_parser) {
				IParser* instance = fn_parser();
				string shapeName = extractExtension(file_name);
				s_factory.registerWith(shapeName, instance);
			}

			if (NULL != fn_converter) {
				IShapeToStringDataConverter* instance = fn_converter();
				string shapeName = extractExtension(file_name);
				c_factory.registerWith(shapeName, instance);			
			}
			
			fRunTimeLinkSuccess = fn_converter && fn_parser;
			
			if (!fRunTimeLinkSuccess) {
				wcout << L"Có lỗi khi đọc file: " << file_name << endl;
				continue;
			}

			hinstLibs.push_back(hinstLib);
		}
	}

	// read file txt and store in a vector
	string input = "shape.txt";
	ifstream reader(input);
	string line = "";
	getline(reader, line);

	vector<IShape*> shapes;

	int count = 0;
	if (reader.good()) {
		// Dùng hàm extractDouble để lấy số hình hiện có
		count = (int)extractDouble(line)[0];

		for (int i = 0; i < count; i++) {
			getline(reader, line);
			stringstream buffer(line);
			string type;
			string data;
			getline(buffer, type, ':');
			getline(buffer, data);

			IParser* parser = s_factory.select(type);
			if (parser != nullptr) {
				IShape* shape = parser->parse(data);
				shapes.push_back(shape);
			}
		}
		reader.close();
	}

	// Convert dữ liệu Shape sang string để in 
	// ra màn hình.
	IShapeToStringDataConverter* converter = nullptr;
	vector<SHAPECONTAINER> container;
	for (auto shape : shapes) {
		converter = c_factory.select(shape->toString());
		container.push_back(converter->convert(shape));
	}


	// In ra màn hình các hình tìm được
	ShapePrinter printer;
	IStrategy* strategy = nullptr;

	// Set strategy cho các trường hợp 
	// đọc được và không đọc được.
	if (count == container.size()) {
		strategy = DetailStrategy::getInstance();
	}
	else {
		strategy = LoadingFailStrategy::getInstance();
	}

	printer.setStrategy(strategy);
	printer.print(container, input, count);
	
	
	// Sắp xếp
	wcout << endl;
	
	// In ra màn hình
	
	strategy = ColumnStrategy::getInstance();
	printer.setStrategy(strategy);
	printer.print(container, input, count);

	// free libs
	for (auto& hinstance : hinstLibs) {
		BOOL freeResult = FreeLibrary(hinstance);

		if (!freeResult) {
			wcout << "fail to free library" << endl;
		}
	}

	system("pause");
	return 0;
}
