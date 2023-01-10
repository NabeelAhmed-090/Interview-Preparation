/* https://leetcode.com/problems/letter-combinations-of-a-phone-number/ */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void recursion(string currentString, int index, int limit,
                   vector<string> &ans, vector<string> choosen)
    {
        if (index >= limit)
        {
            ans.push_back(currentString);
            return;
        }
        for (int i = 0; i < choosen[index].size(); i++)
        {
            string previousString = currentString;
            currentString += choosen[index][i];
            recursion(currentString, index + 1, limit, ans, choosen);
            currentString = previousString;
        }
        return;
    }

    vector<string> letterCombinations(string digits)
    {
        string alphabets[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> numbersChoosen;
        for (int i = 0; i < digits.size(); i++)
            if (digits[i] != '1')
                numbersChoosen.push_back(alphabets[int(digits[i]) - 50]);
        vector<string> ans;
        if (numbersChoosen.size() != 0)
        {
            for (int itr = 0; itr < numbersChoosen[0].size(); itr++)
            {
                string currentString = "";
                currentString += numbersChoosen[0][itr];
                recursion(currentString, 1, numbersChoosen.size(), ans, numbersChoosen);
            }
        }
        return ans;
    }
};