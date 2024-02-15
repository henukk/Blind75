#include <iostream>
#include <string>
#include <vector>

using namespace std;

int numDecodings(string s)
{
    int size = s.size(), one, two;
    if (size == 0 || s[0] == '0')
        return 0;

    vector<int> DP(size + 1, 0);
    DP[0] = 1;
    DP[1] = (s[0] == '0') ? 0 : 1;

    if (s.empty() || s[0] == '0')
        return 0;
    for (int i = 2; i <= size; i++)
    {
        one = stoi(s.substr(i - 1, 1));
        two = stoi(s.substr(i - 2, 2));

        if (one >= 1)
        {
            DP[i] += DP[i - 1];
        }
        if (two >= 10 && two <= 26)
        {
            DP[i] += DP[i - 2];
        }
    }

    return DP[size];
}