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

int kthSmallest(TreeNode *root, int k) {
    int result;
    kthSmallestUtil(root, k, result);
    return result;
}

void kthSmallestUtil(TreeNode *root, int &k, int &result) {
    if (!root)
        return;
    kthSmallestUtil(root->left, k, result);
    if (--k == 0) {
        result = root->val;
        return;
    }
    kthSmallestUtil(root->right, k, result);
}