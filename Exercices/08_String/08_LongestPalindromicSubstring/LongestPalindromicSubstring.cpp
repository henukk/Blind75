#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestPalindrome(string s)
{
    if (s.empty())
        return "";
    int n = s.length();
    vector<int> P(2 * n + 1, 0);
    int C = 0, R = 0;

    for (int i = 0; i < 2 * n + 1; i++)
    {
        int mirror = 2 * C - i;
        if (i < R)
            P[i] = min(R - i, P[mirror]);

        int a = i - (1 + P[i]);
        int b = i + (1 + P[i]);
        while (a >= 0 && b < 2 * n + 1 && ((a % 2 == 0) || (s[a / 2] == s[b / 2])))
        {
            P[i]++;
            a--;
            b++;
        }

        if (i + P[i] > R)
        {
            C = i;
            R = i + P[i];
        }
    }

    int max_length = 0, center_index = 0;
    for (int i = 1; i < 2 * n + 1; i++)
    {
        if (P[i] > max_length)
        {
            max_length = P[i];
            center_index = i;
        }
    }

    return s.substr((center_index - max_length) / 2, max_length);
}