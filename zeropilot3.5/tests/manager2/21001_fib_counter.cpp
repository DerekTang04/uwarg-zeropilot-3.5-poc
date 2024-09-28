#include <gtest/gtest.h>
#include "printer_mock.hpp"
#include "manager2.hpp"

using ::testing::Sequence;

TEST(Manager2Smoke, 21001_CountFibNumbers)
{   
    MockPrinter mockP;
    Manager2 m2(&mockP, FibCounter());

    Sequence s;

    EXPECT_CALL(mockP, print("index: 0    value: 1")).InSequence(s);
    EXPECT_CALL(mockP, print("index: 1    value: 1")).InSequence(s);
    EXPECT_CALL(mockP, print("index: 2    value: 2")).InSequence(s);
    EXPECT_CALL(mockP, print("index: 3    value: 3")).InSequence(s);    
    EXPECT_CALL(mockP, print("index: 4    value: 5")).InSequence(s);
    EXPECT_CALL(mockP, print("index: 5    value: 8")).InSequence(s);
    EXPECT_CALL(mockP, print("index: 6    value: 13")).InSequence(s);
    EXPECT_CALL(mockP, print("index: 7    value: 21")).InSequence(s);
    EXPECT_CALL(mockP, print("index: 8    value: 34")).InSequence(s);
    EXPECT_CALL(mockP, print("index: 9    value: 55")).InSequence(s);
    EXPECT_CALL(mockP, print("index: 0    value: 1")).InSequence(s);

    for(int i = 0; i < 11; ++i)
    {
        m2.mainLoop();
    }
}
