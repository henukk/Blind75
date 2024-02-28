#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countSubstrings(string s)
{
    if (s.empty())
        return 0;
    int n = s.length();
    vector<int> P(2 * n + 1, 0);
    int C = 0, R = 0, result = 0;

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

    for (int i = 0; i < 2 * n + 1; i++)
    {
        result += (P[i] + 1) / 2;
    }

    return result;
}