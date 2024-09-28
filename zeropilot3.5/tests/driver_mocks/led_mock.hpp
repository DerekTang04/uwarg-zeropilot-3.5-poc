#pragma once

#include <gmock/gmock.h>
#include <led_iface.hpp>

class MockLEDBlinker : public ILEDBlinker
{
public:
    MOCK_METHOD(void, blinkOnce, (), (override));
    MOCK_METHOD(void, blinkTwice, (uint32_t delay_ms), (override));
};
