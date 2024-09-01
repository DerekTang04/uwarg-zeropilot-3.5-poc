#include "manager1.hpp"
#include "manager1_defines.hpp"

Manager1::Manager1(ILEDBlinker *ledDriver) : ledDriver(ledDriver), doubleBlink(false)
{
    // left blank
}

void Manager1::mainLoop()
{
    if(doubleBlink)
    {
        ledDriver->blinkTwice(BLINK_TWICE_DELAY_MS);
    }
    else
    {
        ledDriver->blinkOnce();
    }

    doubleBlink = !doubleBlink;
}