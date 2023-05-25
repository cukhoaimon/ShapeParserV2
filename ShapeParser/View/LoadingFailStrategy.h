#pragma once 
#include "IStrategy.h"


/*
=============================== Define class ============================
*/
class LoadingFailStrategy
	: public IStrategy
{
private:
	inline static LoadingFailStrategy* _instance = nullptr;
	LoadingFailStrategy() {};

public:
	static LoadingFailStrategy* getInstance();

	void execute(vector<SHAPECONTAINER> container, string file_name, int expected) override;
	string toString();
};