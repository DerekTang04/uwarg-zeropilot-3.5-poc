#pragma once

#include "fibonacci.hpp"
#include "printer_iface.hpp"

class Manager2
{
private:
    IPrinter *printerDriver;
    FibCounter helperCounter;

public:
    Manager2() = delete;

    Manager2(IPrinter *printerDriver, FibCounter helperCounter);

    void mainLoop();
};