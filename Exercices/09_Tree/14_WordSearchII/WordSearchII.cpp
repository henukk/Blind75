#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TrieNode {
    vector<TrieNode *> children;
    string word;
    TrieNode() : children(26, nullptr), word("") {}
    ~TrieNode() {
        for (auto child : children)
            delete child;
    }
};

class Solution {
    void insertWord(TrieNode *root, const string &word) {
        TrieNode *node = root;
        for (char ch : word) {
            if (!node->children[ch - 'a'])
                node->children[ch - 'a'] = new TrieNode();
            node = node->children[ch - 'a'];
        }
        node->word = word;
    }

    void dfs(vector<vector<char>> &board, int x, int y, TrieNode *node,
             vector<string> &result) {
        char ch = board[x][y];
        if (ch == '#' || !node->children[ch - 'a'])
            return;

        node = node->children[ch - 'a'];
        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word = "";
        }

        board[x][y] = '#';
        if (x > 0)
            dfs(board, x - 1, y, node, result);
        if (y > 0)
            dfs(board, x, y - 1, node, result);
        if (x < board.size() - 1)
            dfs(board, x + 1, y, node, result);
        if (y < board[0].size() - 1)
            dfs(board, x, y + 1, node, result);
        board[x][y] = ch;
    }

  public:
    vector<string> findWords(vector<vector<char>> &board,
                             vector<string> &words) {
        TrieNode *root = new TrieNode();
        for (const string &word : words) {
            insertWord(root, word);
        }

        vector<string> result;
        for (int x = 0; x < board.size(); x++) {
            for (int y = 0; y < board[0].size(); y++) {
                dfs(board, x, y, root, result);
            }
        }

        delete root;
        return result;
    }
};