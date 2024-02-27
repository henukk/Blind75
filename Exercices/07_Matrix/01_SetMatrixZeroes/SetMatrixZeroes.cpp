#include <iostream>
#include <vector>
#include <list>

using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size(), i, j;
    list<pair<int, int>> zeros;
    pair<int, int> act;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; ++j)
        {
            if (matrix[i][j] == 0)
            {
                zeros.emplace_back(i, j);
            }
        }
    }

    while (!zeros.empty())
    {
        act = zeros.back();
        zeros.pop_back();
        for (i = 0; i < n; ++i)
        {
            matrix[i][act.second] = 0;
        }
        for (i = 0; i < m; ++i)
        {
            matrix[act.first][i] = 0;
        }
    }
}