#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> result = vector<vector<int>>(0);
    int size = nums.size();
    int j, k, sum;
    for (int i = 0; i < size; i++)
    {
        if (i == 0 || nums[i] != nums[i - 1])
        {
            j = i + 1;
            k = size - 1;
            while (j < k)
            {
                sum = nums[i] + nums[j] + nums[k];
                if (sum < 0)
                {
                    ++j;
                }
                else if (sum > 0)
                {
                    --k;
                }
                else
                {
                    result.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1])
                        ++j;
                    while (j < k && nums[k] == nums[k - 1])
                        --k;
                    ++j;
                    --k;
                }
            }
        }
    }

    return result;
}