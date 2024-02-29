#include <ListNode>
#include <iostream>
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

ListNode *mergeKLists(vector<ListNode *> &lists) {
    priority_queue<int, vector<int>, greater<int>> order;
    int i, size = lists.size();
    for (i = 0; i < size; ++i) {
        while (lists[i]) {
            order.push(lists[i]->val);
            lists[i] = lists[i]->next;
        }
    }
    ListNode result(0);
    ListNode *cur = &result;
    while (!order.empty()) {
        cur->next = new ListNode(order.top());
        order.pop();
        cur = cur->next;
    }

    return result.next;
}