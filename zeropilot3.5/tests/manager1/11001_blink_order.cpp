#include <gtest/gtest.h>
#include "led_mock.hpp"
#include "manager1.hpp"

using ::testing::Sequence;
using ::testing::_;

TEST(Manager1Smoke, 11001_BlinkOnceBeforeTwice)
{
    // define objects
    MockLEDBlinker mockLED;
    Manager1 m1(&mockLED);

    // define gtest objects
    Sequence s;

    // define expectations
    EXPECT_CALL(mockLED, blinkOnce()).InSequence(s);
    EXPECT_CALL(mockLED, blinkTwice(_)).InSequence(s);

    // run test
    m1.mainLoop();
}
