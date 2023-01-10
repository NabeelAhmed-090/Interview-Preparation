/* https://leetcode.com/problems/merge-two-sorted-lists/ */

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
    void finishMerge(ListNode *list, ListNode *&mergeList, ListNode *&previous)
    {
        while (list)
        {
            mergeList->val = list->val;
            mergeList->next = new ListNode;
            previous = mergeList;
            mergeList = mergeList->next;
            list = list->next;
        }
    }
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1 && !list2)
            return NULL;
        if (list1 && !list2)
            return list1;
        if (!list1 && list2)
            return list2;
        ListNode *mergeList = new ListNode;
        ListNode *traverse = mergeList, *previous = mergeList;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                traverse->val = list1->val;
                list1 = list1->next;
            }
            else
            {
                traverse->val = list2->val;
                list2 = list2->next;
            }
            traverse->next = new ListNode;
            previous = traverse;
            traverse = traverse->next;
        }

        if (list1)
            finishMerge(list1, traverse, previous);
        else if (list2)
            finishMerge(list2, traverse, previous);

        previous->next = NULL;
        traverse = NULL;
        return mergeList;
    }
};