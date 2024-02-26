#include <iostream>
#include <ListNode>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

public:
struct compare
{
    bool operator()(const ListNode *l1, const ListNode *l2)
    {
        return l1->val > l2->val;
    }
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    priority_queue<ListNode *, vector<ListNode *>, compare> pq;

    for (ListNode *list : lists)
    {
        if (list)
            pq.push(list);
    }

    ListNode tmp;
    ListNode *tail = &tmp;

    while (!pq.empty())
    {
        tail->next = pq.top();
        pq.pop();
        tail = tail->next;

        if (tail->next)
            pq.push(tail->next);
    }

    return tmp.next;
}