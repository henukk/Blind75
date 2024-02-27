#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    vector<int> result;
    result.reserve(n * m);

    int top = 0, bottom = n - 1, left = 0, right = m - 1, i, j;

    while (top <= bottom && left <= right)
    {
        for (j = left; j <= right; j++)
        {
            result.push_back(matrix[top][j]);
        }
        top++;

        for (i = top; i <= bottom; i++)
        {
            result.push_back(matrix[i][right]);
        }
        right--;

        if (top <= bottom)
        {
            for (j = right; j >= left; j--)
            {
                result.push_back(matrix[bottom][j]);
            }
            bottom--;
        }

        if (left <= right)
        {
            for (i = bottom; i >= top; i--)
            {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return result;
}