#pragma once 
#include "IStrategy.h"


/*
=============================== Define class ============================
*/

class DetailStrategy
	: public IStrategy
{
private:
	inline static DetailStrategy* _instance = nullptr;
	DetailStrategy();

public:
	static DetailStrategy* getInstance();

	void execute(vector<SHAPECONTAINER> container, string file_name, int expected) override;
	string toString();
};