#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxProduct(vector<int> &nums)
{
    int size = nums.size();
    int act = 1, ret = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        act *= nums[i];
        ret = max(ret, act);
        if (act == 0)
            act = 1;
    }

    act = 1;
    for (int i = size - 1; i >= 0; i--)
    {
        act *= nums[i];
        ret = max(ret, act);
        if (act == 0)
            act = 1;
    }

    return ret;
}
