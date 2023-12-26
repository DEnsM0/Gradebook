#pragma once
#include "Exception.h"
class MarkExc :
    virtual public Exception
{
public:
    MarkExc(uint);
    virtual void print() override;
};

