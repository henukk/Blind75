#include <iostream>
#include <vector>

using namespace std;

int uniquePaths(int m, int n)
{
    vector<vector<int>> DP(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        DP[i][0] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        DP[0][i] = 1;
    }

    for (int i = 1; i < m; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            DP[i][j] += DP[i - 1][j] + DP[i][j - 1];
        }
    }

    return DP[m - 1][n - 1];
}