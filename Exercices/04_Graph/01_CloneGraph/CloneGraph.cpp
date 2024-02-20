#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

unordered_map<Node*, Node*> cloned;
Node *cloneGraph(Node *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    if (cloned.find(node) != cloned.end())
    {
        return cloned[node];
    }

    Node *act = new Node(node->val);
    cloned[node] = act;

    for (Node *neighbor : node->neighbors)
    {
        act->neighbors.push_back(cloneGraph(neighbor));
    }

    return act;
}