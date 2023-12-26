#pragma once
#include "Header.h"

class Exception abstract
{
protected:
	using uint = unsigned int;
	uint val;
	struct tm date;
public:
	Exception(uint);
	Exception(struct tm);
	virtual void print() = 0;
};

