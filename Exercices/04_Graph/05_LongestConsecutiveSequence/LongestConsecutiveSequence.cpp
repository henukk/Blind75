#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> numSet(nums.begin(), nums.end());
    int result = 0;

    for (int num : nums)
    {
        if (!numSet.count(num - 1))
        {
            int currentNum = num;
            int currentStreak = 1;

            while (numSet.count(currentNum + 1))
            {
                currentNum += 1;
                currentStreak += 1;
            }

            result = max(result, currentStreak);
        }
    }

    return result;
}