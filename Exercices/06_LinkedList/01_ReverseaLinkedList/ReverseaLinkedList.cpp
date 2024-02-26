#include <iostream>
#include <ListNode>

using namespace std;

/**
 * Singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

ListNode *reverseList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    ListNode *tmp = NULL, *current = head, *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = tmp;
        tmp = current;
        current = next;
    }

    return tmp;
}