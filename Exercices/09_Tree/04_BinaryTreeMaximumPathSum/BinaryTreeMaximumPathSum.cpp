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

int maxPathSumUtil(TreeNode *root, int &maxSum) {
    if (root == nullptr)
        return 0;

    int left = max(0, maxPathSumUtil(root->left, maxSum));
    int right = max(0, maxPathSumUtil(root->right, maxSum));

    maxSum = max(maxSum, left + right + root->val);

    return max(left, right) + root->val;
}

int maxPathSum(TreeNode *root) {
    int maxSum = INT_MIN;
    maxPathSumUtil(root, maxSum);
    return maxSum;
}