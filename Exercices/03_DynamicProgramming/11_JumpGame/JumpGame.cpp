#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int> &nums)
{
    int size = nums.size(), act = 0;
    for (int i = 0; i < size; ++i)
    {
        if (i > act)
            return false;
        act = max(act, i + nums[i]);
        if (act >= size - 1)
            return true;
    }
    return false;
}