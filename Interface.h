#pragma once
#include "Header.h"
class Interface abstract
{
public:
	// віртуальні ф-ції:
	virtual void fill() = 0;
	virtual void print() const = 0;
	virtual string toString() const = 0;
};

