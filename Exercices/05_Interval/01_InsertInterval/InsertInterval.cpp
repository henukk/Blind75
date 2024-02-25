#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>> merged;

    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[0] < b[0]; });

    for (auto &interval : intervals)
    {
        if (merged.empty() || merged.back()[1] < interval[0])
        {
            merged.push_back(interval);
        }
        else
        {
            merged.back()[1] = max(merged.back()[1], interval[1]);
        }
    }

    return merged;
}