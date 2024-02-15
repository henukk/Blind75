#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return nums[0];

    vector<int> DP(n);
    DP[0] = nums[0];
    DP[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; ++i)
    {
        DP[i] = max(DP[i - 1], nums[i] + DP[i - 2]);
    }

    return DP[n - 1];
}