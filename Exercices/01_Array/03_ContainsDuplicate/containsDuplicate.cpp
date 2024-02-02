#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    unordered_set<int> list;

    for (int i = 0; i < nums.size(); ++i)
    {
        if (!list.insert(nums[i]).second)
            return true;
    }
    return false;
}