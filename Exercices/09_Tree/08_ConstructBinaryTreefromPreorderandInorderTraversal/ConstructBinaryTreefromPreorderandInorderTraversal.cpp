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

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return buildTreeUtil(preorder, 0, preorder.size(), inorder, 0,
                         inorder.size());
}

TreeNode *buildTreeUtil(vector<int> &preorder, int preStart, int preEnd,
                        vector<int> &inorder, int inStart, int inEnd) {
    if (preStart >= preEnd || inStart >= inEnd)
        return nullptr;

    int rootVal = preorder[preStart];
    TreeNode *root = new TreeNode(rootVal);

    int inRootPos =
        find(inorder.begin() + inStart, inorder.begin() + inEnd, rootVal) -
        inorder.begin();
    int leftSubtreeSize = inRootPos - inStart;

    root->left =
        buildTreeUtil(preorder, preStart + 1, preStart + 1 + leftSubtreeSize,
                      inorder, inStart, inRootPos);
    root->right = buildTreeUtil(preorder, preStart + 1 + leftSubtreeSize,
                                preEnd, inorder, inRootPos + 1, inEnd);

    return root;
}