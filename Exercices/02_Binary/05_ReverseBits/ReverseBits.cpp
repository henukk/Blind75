#include <iostream>

using namespace std;

uint32_t reverseBits(uint32_t n)
{
    uint32_t ret = 0;
    uint32_t act = 2147483648;

    for (int i = 0; i < 32; ++i)
    {
        if (n & 1)
        {
            ret |= act;
        }
        n >>= 1;
        act >>= 1;
    }
    return ret;
}