#pragma once
#include "Exception.h"
class DateExc :
    public Exception
{
public:
    DateExc(struct tm);
    virtual void print() override;
};

