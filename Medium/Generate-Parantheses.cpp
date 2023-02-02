/* https://leetcode.com/problems/generate-parentheses/ */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    struct ListNode
    {
        string val;
        ListNode *leftChild;
        ListNode *rightChild;
        ListNode(string val) : val(val), leftChild(nullptr), rightChild(nullptr) {}
    };

    void recursiveFunction(ListNode *&node, string val, vector<string> &ans, int openCount,
                           int closeCount, int n)
    {
        node = new ListNode(val);
        if (openCount < n)
        {
            recursiveFunction(node->leftChild, val + "(", ans,
                              openCount + 1, closeCount, n);
        }
        if (openCount > closeCount)
        {
            recursiveFunction(node->rightChild, val + ")", ans,
                              openCount, closeCount + 1, n);
        }
        if (openCount == n && closeCount == n)
        {
            ans.push_back(val);
        }
    }
    vector<string> generateParenthesis(int n)
    {
        ListNode *head;
        vector<string> ans;
        recursiveFunction(head, "(", ans, 1, 0, n);
        return ans;
    }
};