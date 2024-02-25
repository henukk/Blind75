#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> merged;

    sort(
        intervals.begin(),
        intervals.end(),
        [](const vector<int> &a, const vector<int> &b)
            { return a[0] < b[0]; }
    );

    merged.push_back(intervals[0]);
    int last = intervals[0][1], i = 0;
    for (auto act : intervals)
    {
        if (last >= act[0])
        {
            last = max(act[1], last);
            merged[i][1] = max(act[1], last);
        }
        else
        {
            merged.push_back(act);
            last = act[1];
            ++i;
        }
    }

    return merged;
}