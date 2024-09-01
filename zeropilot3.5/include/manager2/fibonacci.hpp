#pragma once

#include <cstdint>

class FibCounter
{
private:
    uint8_t idx;
    uint8_t num1;
    uint8_t num2;

public:
    typedef struct
    {
        uint8_t idx;
        uint8_t val;
    } IdxValPair;

    FibCounter();

    IdxValPair getNextFib();
};