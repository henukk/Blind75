#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) >> 1;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] >= nums[left])
        {
            if (target >= nums[left] && target <= nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        else
        {
            if (target >= nums[mid] && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}