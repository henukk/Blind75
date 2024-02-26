#include <iostream>
#include <ListNode>

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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (n == 1 && !head->next)
    {
        return NULL;
    }
    if (n == 1 && !head->next->next)
    {
        head->next = NULL;
        return head;
    }

    ListNode *a = head;
    ListNode *b = head;
    for (int i = 0; i < n; ++i)
    {
        b = b->next;
    }

    if (!b)
        return a->next;

    while (b->next)
    {
        b = b->next;
        a = a->next;
    }

    a->next = a->next->next;
    return head;
}