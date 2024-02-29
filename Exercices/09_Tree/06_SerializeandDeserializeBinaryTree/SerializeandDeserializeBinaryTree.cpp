#include <TreeNode>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Encodes a tree to a single string.
string serialize(TreeNode *root) {
    if (!root)
        return "n ";
    return to_string(root->val) + " " + serialize(root->left) + ' ' +
           serialize(root->right);
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data) {
    stringstream ss(data);
    return deserializeHelper(ss);
}

TreeNode *deserializeHelper(stringstream &ss) {
    string val;
    ss >> val;

    if (val == "n")
        return nullptr;

    TreeNode *node = new TreeNode(stoi(val));
    node->left = deserializeHelper(ss);
    node->right = deserializeHelper(ss);

    return node;
}