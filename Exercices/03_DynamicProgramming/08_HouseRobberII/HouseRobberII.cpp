#include <iostream>
#include <vector>

using namespace std;

int robRange(vector<int> &nums, int start, int end)
{
    if (start == end)
        return nums[start];

    vector<int> dp(end, 0);
    dp[start] = nums[start];
    dp[start + 1] = max(nums[start], nums[start + 1]);

    for (int i = start + 2; i < end; ++i)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[end - 1];
}

int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    if (n == 2)
        return max(nums[0], nums[1]);

    return max(robRange(nums, 0, n - 1), robRange(nums, 1, n));
}