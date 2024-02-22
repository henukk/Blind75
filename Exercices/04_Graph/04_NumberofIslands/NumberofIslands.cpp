#include <iostream>
#include <vector>

using namespace std;

int numIslands(vector<vector<char>> &grid)
{
    int result = 0, n = grid.size(), m = grid[0].size();
    vector<vector<int>> islands(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] != '0' && islands[i][j] == 0)
            {
                ++result;
                dfs(grid, islands, result, i, j);
            }
        }
    }
    return result;
}

void dfs(const vector<vector<char>> &grid, vector<vector<int>> &islands, int act, int i, int j)
{
    int n = grid.size(), m = grid[0].size();
    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0' || islands[i][j] != 0)
    {
        return;
    }
    islands[i][j] = act;

    dfs(grid, islands, act, i + 1, j);
    dfs(grid, islands, act, i - 1, j);
    dfs(grid, islands, act, i, j + 1);
    dfs(grid, islands, act, i, j - 1);
}