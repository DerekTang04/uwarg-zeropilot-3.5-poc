#pragma once

#include <cstdint>

class ILEDBlinker
{
protected:
    ILEDBlinker() = default;

public:
    virtual ~ILEDBlinker() = default;

    virtual void blinkOnce() = 0;

    virtual void blinkTwice(uint32_t delay_ms) = 0;
};