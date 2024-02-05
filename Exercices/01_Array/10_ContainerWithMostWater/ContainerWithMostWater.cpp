#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int> &height)
{
    int i = 0, j = height.size() - 1;
    int maxArea = 0, act;
    while (i < j)
    {
        maxArea = max(maxArea, min(height[i], height[j]) * (j - i));
        if (height[i] < height[j])
            i++;
        else
            j--;
    }
    return maxArea;
}