#include <iostream>
#include <vector>
#include <string>

using namespace std;

string minWindow(string s, string t)
{
    if (s.size() < t.size())
        return "";

    vector<int> freq_t(128, 0), freq_s(128, 0);
    for (char c : t)
        freq_t[c]++;

    int start = 0, minLen = INT_MAX, minStart = 0;
    int required = t.size(), count = 0;

    for (int end = 0; end < s.size(); end++)
    {
        if (freq_t[s[end]] > freq_s[s[end]])
            count++;
        freq_s[s[end]]++;

        while (count == required)
        {
            if (end - start + 1 < minLen)
            {
                minLen = end - start + 1;
                minStart = start;
            }

            freq_s[s[start]]--;
            if (freq_s[s[start]] < freq_t[s[start]])
                count--;
            start++;
        }
    }

    return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
}