#pragma once

#include <gmock/gmock.h>
#include "printer_iface.hpp"

class MockPrinter : public IPrinter
{
public:
    MOCK_METHOD(void, print, (char *str), (override));
};
