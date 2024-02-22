#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    vector<vector<int>> result;
    int n = heights.size(), m = heights[0].size();

    vector<vector<bool>> pacificFlow(n, vector<bool>(m, false));
    vector<vector<bool>> atlanticFlow(n, vector<bool>(m, false));

    for (int i = 0; i < n; ++i)
    {
        dfs(heights, pacificFlow, -1, i, 0);
        dfs(heights, atlanticFlow, -1, i, m - 1);
    }
    for (int j = 0; j < m; ++j)
    {
        dfs(heights, pacificFlow, -1, 0, j);
        dfs(heights, atlanticFlow, -1, n - 1, j);
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (pacificFlow[i][j] && atlanticFlow[i][j])
            {
                result.push_back({i, j});
            }
        }
    }

    return result;
}

void dfs(const vector<vector<int>> &heights, vector<vector<bool>> &flow, int prevHeight, int i, int j)
{
    int n = heights.size(), m = heights[0].size();
    if (i < 0 || j < 0 || i >= n || j >= m || flow[i][j] || heights[i][j] < prevHeight)
    {
        return;
    }
    flow[i][j] = true;

    dfs(heights, flow, heights[i][j], i + 1, j);
    dfs(heights, flow, heights[i][j], i - 1, j);
    dfs(heights, flow, heights[i][j], i, j + 1);
    dfs(heights, flow, heights[i][j], i, j - 1);
}