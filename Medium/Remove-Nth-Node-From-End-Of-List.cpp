/* https://leetcode.com/problems/remove-nth-node-from-end-of-list/ */

#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *current = head;
        ListNode *previous = head;
        int nodes = 0;
        if (n == 1)
        {
            while (current->next)
            {
                previous = current;
                current = current->next;
                nodes++;
            }
            if (nodes == 0)
                return NULL;
            else
            {
                delete current;
                previous->next = NULL;
                return head;
            }
        }
        else
        {
            int count = 0;
            while (current)
            {
                current = current->next;
                if (count >= n)
                {
                    if (current)
                    {
                        previous = previous->next;
                    }
                }
                count++;
            }
            if (count == n)
            {
                ListNode *startNode = head->next;
                delete head;
                head = startNode;
            }
            else
            {
                ListNode *skipNode = previous->next->next;
                delete previous->next;
                previous->next = skipNode;
            }
            return head;
        }
    }
};