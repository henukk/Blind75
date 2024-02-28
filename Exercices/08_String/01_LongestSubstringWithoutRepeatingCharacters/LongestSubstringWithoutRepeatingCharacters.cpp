#include <iostream>
#include <string>
#include <vector>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    int slow = 0, fast = 0, size = s.size(), result = 0;
    vector<int> index(256, -1);

    while (fast < size)
    {
        if (index[s[fast]] != -1)
        {
            slow = max(slow, index[s[fast]] + 1);
            cout << slow << endl;
        }

        index[s[fast]] = fast;
        result = max(result, fast - slow + 1);
        fast++;
    }

    return result;
}