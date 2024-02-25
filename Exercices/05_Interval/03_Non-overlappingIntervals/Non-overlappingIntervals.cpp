#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    if (intervals.empty())
        return 0;

    sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[0] < b[0]; });

    int removeCount = 0;
    int end = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] < end)
        {
            removeCount++;
            end = min(end, intervals[i][1]);
        }
        else
        {
            end = intervals[i][1];
        }
    }

    return removeCount;
}