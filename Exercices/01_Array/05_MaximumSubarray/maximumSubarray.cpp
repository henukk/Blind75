#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int> &nums)
{
    int size = nums.size();
    int act = nums[0], tmp = nums[0];

    for (int i = 1; i < size; i++)
    {
        act = max(nums[i], act + nums[i]);
        tmp = max(tmp, act);
    }

    if (tmp > act)
        return tmp;

    return act;
}