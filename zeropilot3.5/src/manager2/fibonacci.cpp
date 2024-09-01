#include <algorithm>
#include "fibonacci.hpp"

FibCounter::FibCounter() : idx(0), num1(1), num2(1)
{
    // left blank
}

FibCounter::IdxValPair FibCounter::getNextFib()
{
    IdxValPair ret;
    
    if(idx < 2)
    {
        ret = {idx, 1};
    }
    else if(idx == 10)
    {
        idx = 0;
        num1 = 1;
        num2 = 1;

        ret = {idx, 1};
    }
    else
    {   
        uint8_t sum = num1 + num2;

        std::swap(num1, num2);
        num2 = sum;

        ret = {idx, sum};
    }

    ++idx;
    return ret;
}