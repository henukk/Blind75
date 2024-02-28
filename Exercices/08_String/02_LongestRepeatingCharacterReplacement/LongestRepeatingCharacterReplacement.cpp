#include <iostream>
#include <vector>
#include <string>

using namespace std;

int characterReplacement(string s, int k)
{
    vector<int> count(26, 0);
    int maxCount = 0;
    int start = 0;
    int maxLength = 0;

    for (int end = 0; end < s.size(); ++end)
    {
        maxCount = max(maxCount, ++count[s[end] - 'A']);

        if (end - start + 1 - maxCount > k)
        {
            --count[s[start] - 'A'];
            ++start;
        }

        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
}