#include <gtest/gtest.h>
#include "fibonacci.hpp"

TEST(Manager2Smoke, 21001_CountFibNumbers)
{   
    FibCounter fib;

    FibCounter::IdxValPair expOut[] = {
        {0, 1},
        {1, 1},
        {2, 2},
        {3, 3},
        {4, 5},
        {5, 8},
        {6, 13},
        {7, 21},
        {8, 34},
        {9, 55},
        {0, 1}
    };

    for(int i = 0; i < 11; ++i )
    {
        FibCounter::IdxValPair ret = fib.getNextFib();

        EXPECT_EQ(ret.idx, expOut[i].idx);
        EXPECT_EQ(ret.val, expOut[i].val);
    }
}
