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

bool isValidBST(TreeNode *root) {
    if (!root)
        return true;

    return isValidBSTUtil(root, LONG_MIN, LONG_MAX);
}

bool isValidBSTUtil(TreeNode *root, long long low, long long high) {
    if (!root)
        return true;
    if (root->val <= low || root->val >= high)
        return false;

    return isValidBSTUtil(root->left, low, root->val) &&
           isValidBSTUtil(root->right, root->val, high);
}