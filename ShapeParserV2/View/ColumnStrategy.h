#pragma once 
#include "IStrategy.h"


/*
=============================== Define class ============================
*/

class ColumnStrategy
	: public IStrategy
{
private:
	inline static ColumnStrategy* _instance = nullptr;
	ColumnStrategy();

public:
	static ColumnStrategy* getInstance();

	void execute(vector<SHAPECONTAINER> container, string file_name, int expected) override;
	string toString();

};