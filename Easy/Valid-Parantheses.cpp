/* https://leetcode.com/problems/valid-parentheses/ */

#include <stack>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool checkBracket(char bracket)
    {
        if (bracket == '(' || bracket == '{' || bracket == '[')
            return true;
        return false;
    }
    bool isValid(string s)
    {
        stack<char> stack;
        for (int i = 0; i < s.size(); i++)
        {
            if (checkBracket(s[i]))
                stack.push(s[i]);
            else
            {
                if (stack.size() == 0)
                    return false;
                char stackBracket = stack.top();
                if ((s[i] == ')' && stackBracket != '(') ||
                    (s[i] == '}' && stackBracket != '{') ||
                    (s[i] == ']' && stackBracket != '['))
                    return false;
                stack.pop();
            }
        }
        if (stack.size() == 0)
            return true;
        return false;
    }
};