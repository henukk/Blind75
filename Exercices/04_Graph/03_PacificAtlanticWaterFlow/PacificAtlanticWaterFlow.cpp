#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    vector<vector<int>> result(0);

    int n = heights.size(), m = heights[0].size();

    // Posible Optimization
    vector<vector<int>> waterFlow(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (checkOceans(i, j, heights, waterFlow))
            {
                waterFlow[i][j] = 1;
                result.push_back({i, j});
            }
            else
            {
                waterFlow[i][j] = -1;
            }
        }
    };

    return result;
}

bool checkOceans(int a, int b, vector<vector<int>> &heights, vector<vector<int>> &waterFlow)
{
    int n = heights.size() - 1, m = heights[0].size() - 1;
    bool pacific = false, atlantic = false;
    stack<pair<int, int>> toVisit;
    vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));

    toVisit.push({a, b});
    pair<int, int> act;
    while (!toVisit.empty())
    {
        act = toVisit.top();
        toVisit.pop();
        visited[act.first][act.second] = true;

        if (act.first == 0 || act.second == 0)
            pacific = true;
        if (act.first == n || act.second == m)
            atlantic = true;

        if (act.first > 0 && !visited[act.first - 1][act.second] && heights[act.first][act.second] >= heights[act.first - 1][act.second])
            if (waterFlow[act.first - 1][act.second] == 0)
                toVisit.push({act.first - 1, act.second});
            else if (waterFlow[act.first - 1][act.second] == 1)
                return true;
        if (act.second > 0 && !visited[act.first][act.second - 1] && heights[act.first][act.second] >= heights[act.first][act.second - 1])
            if (waterFlow[act.first][act.second - 1] == 0)
                toVisit.push({act.first, act.second - 1});
            else if (waterFlow[act.first][act.second - 1] == 1)
                return true;
        if (act.first < n && !visited[act.first + 1][act.second] && heights[act.first][act.second] >= heights[act.first + 1][act.second])
            if (waterFlow[act.first + 1][act.second] == 0)
                toVisit.push({act.first + 1, act.second});
            else if (waterFlow[act.first + 1][act.second] == 1)
                return true;
        if (act.second < m && !visited[act.first][act.second + 1] && heights[act.first][act.second] >= heights[act.first][act.second + 1])
            if (waterFlow[act.first][act.second + 1] == 0)
                toVisit.push({act.first, act.second + 1});
            else if (waterFlow[act.first][act.second + 1] == 1)
                return true;
    }

    return pacific && atlantic;
}
