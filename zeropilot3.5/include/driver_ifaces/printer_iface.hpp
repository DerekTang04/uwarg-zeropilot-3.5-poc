#pragma once

class IPrinter
{
protected:
    IPrinter() = default;

public:
    virtual ~IPrinter() = default;

    virtual void print(char *str) = 0;
};