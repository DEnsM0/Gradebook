#pragma once
#include "Exception.h"
class HoursExc :
    public Exception
{
public:
    HoursExc(uint);
    virtual void print() override;
};

