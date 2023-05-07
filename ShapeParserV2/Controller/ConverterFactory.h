#include "IShapeToStringDataConverter.h"

#include <map>
#include <string>

using std::map, std::string;

class ConverterFactory
{
private:
	map<string, IShapeToStringDataConverter*> _prototypes;

public:
	void registerWith(string, IShapeToStringDataConverter*);

	IShapeToStringDataConverter* select(string);
};