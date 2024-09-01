#include <cstdio>
#include "manager2.hpp"

Manager2::Manager2(IPrinter *printerDriver, FibCounter helperCounter) : printerDriver(printerDriver), helperCounter(helperCounter)
{
    // left blank
}

void Manager2::mainLoop()
{
    FibCounter::IdxValPair res = helperCounter.getNextFib();

    char buf[100];
    snprintf(buf, sizeof(buf), "index: %u    value: %u", res.idx, res.val);
    printerDriver->print(buf);
}
