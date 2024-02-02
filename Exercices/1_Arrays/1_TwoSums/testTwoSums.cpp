#include "twoSums.cpp"
#include <cassert>

using namespace std;

void testTwoSums() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    assert(result.size() == 2);
    assert(nums[result[0]] + nums[result[1]] == target);
}

int main() {
    testTwoSums();
    cout << "All tests passed!" << endl;
    return 0;
}