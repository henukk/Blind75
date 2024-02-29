#include <TreeNode>
#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> result;
    int i, size;
    queue<TreeNode *> q;
    TreeNode *tmp;
    if (root)
        q.push(root);

    while (!q.empty()) {
        result.push_back(vector<int>());
        size = q.size();

        for (i = 0; i < size; ++i) {
            tmp = q.front();
            q.pop();
            result.back().push_back(tmp->val);
            if (tmp->left)
                q.push(tmp->left);
            if (tmp->right)
                q.push(tmp->right);
        }
    }

    return result;
}