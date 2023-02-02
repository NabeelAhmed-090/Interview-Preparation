/* https://leetcode.com/problems/add-two-numbers/ */

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <cmath>
class Solution
{
public:
    void carryForwardValue(int &val, int &carryForward)
    {
        if (val >= 10)
        {
            carryForward = val / 10;
            val %= 10;
        }
        else
            carryForward = 0;
    }
    void completeList(ListNode *L, ListNode *&traverse, ListNode *&previous, int carryForward)
    {
        while (L)
        {
            int val = L->val + carryForward;
            carryForwardValue(val, carryForward);
            traverse->val = val;
            previous = traverse;
            traverse->next = new ListNode;
            traverse = traverse->next;
            L = L->next;
        }
        if (carryForward == 0)
            previous->next = NULL;
        else
        {
            traverse->val = carryForward;
            traverse->next = NULL;
        }
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *tempL1 = l1, *tempL2 = l2, *result = new ListNode;
        ListNode *traverse = result, *previous;
        int carryForward = 0;
        while (tempL1 && tempL2)
        {
            int val = tempL1->val + tempL2->val + carryForward;
            carryForwardValue(val, carryForward);
            traverse->val = val;
            previous = traverse;
            traverse->next = new ListNode;
            traverse = traverse->next;
            tempL1 = tempL1->next;
            tempL2 = tempL2->next;
        }
        if (!tempL1 && !tempL2)
        {
            if (carryForward == 0)
                previous->next = NULL;
            else
            {
                traverse->val = carryForward;
                traverse->next = NULL;
            }
        }
        else if (tempL1 && !tempL2)
            completeList(tempL1, traverse, previous, carryForward);
        else
            completeList(tempL2, traverse, previous, carryForward);
        return result;
    }
};