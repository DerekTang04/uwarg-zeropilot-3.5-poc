#pragma once

#include "led_iface.hpp"

class Manager1
{
private:
    ILEDBlinker *ledDriver;
    bool doubleBlink;

public:
    Manager1() = delete;

    Manager1(ILEDBlinker *ledDriver);

    void mainLoop();
};