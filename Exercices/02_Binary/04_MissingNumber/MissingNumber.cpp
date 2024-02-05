#include <iostream>

using namespace std;

int missingNumber(vector<int> &nums)
{
    int i, size = nums.size();
    int a = 0;
    int b = size * (size + 1) / 2;
    for (i = 0; i < size; ++i)
    {
        a += nums[i];
    }
    return (b - a);
}