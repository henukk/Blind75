#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    vector<int> subs;

    for (int x : nums)
    {
        auto it = lower_bound(subs.begin(), subs.end(), x);
        if (it == subs.end())
        {
            subs.push_back(x);
        }
        else
        {
            *it = x;
        }
    }

    return subs.size();
}