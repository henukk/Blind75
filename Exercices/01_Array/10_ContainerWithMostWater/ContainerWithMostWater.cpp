#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxArea(vector<int> &height)
{
    int size = height.size();
    int i = 0, j = size - 1;
    long long maxArea = INT_MIN;

    while (i < j)
    {
        maxArea = max(maxArea, min(height[i], height[j]) * (j - i));
        if (height[i] < height[j])
            i++;
        else
            j++;
    }

    return maxArea;
}