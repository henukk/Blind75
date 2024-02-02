#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int size = nums.size();
    unordered_map<int, int> remaining;

    for (int i = 0; i < size; i++)
    {
        int tmp = target - nums[i];
        if (remaining.find(tmp) != remaining.end())
            return {remaining[tmp], i};
        remaining[nums[i]] = i;
    }
    return {};
}
