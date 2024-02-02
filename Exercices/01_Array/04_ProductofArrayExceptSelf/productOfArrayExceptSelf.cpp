#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int size = nums.size();
    vector<int> ret = vector<int>(size);
    fill(ret.begin(), ret.end(), 1);

    int tmp = 1;

    for (int i = 0; i < size; i++)
    {
        ret[i] = tmp;
        tmp *= nums[i];
    }
    tmp = 1;
    for (int i = size - 1; i >= 0; i--)
    {
        ret[i] *= tmp;
        tmp *= nums[i];
    }

    return ret;
}