#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool exist(vector<vector<char>> &board, string word)
{
    int n = board.size(), m = board[0].size(), i, j;

    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            if (check(i, j, board, word, 0))
                return true;
        }
    }

    return false;
}

bool check(int a, int b, vector<vector<char>> &board, string &word, int act)
{
    if (act == word.size())
        return true;
    if (a < 0 || b < 0 || a >= board.size() || b >= board[0].size() || board[a][b] != word[act])
    {
        return false;
    }

    char tmp = board[a][b];
    board[a][b] = '.';

    bool found = check(a - 1, b, board, word, act + 1) ||
                 check(a + 1, b, board, word, act + 1) ||
                 check(a, b - 1, board, word, act + 1) ||
                 check(a, b + 1, board, word, act + 1);

    board[a][b] = tmp;

    return found;
};