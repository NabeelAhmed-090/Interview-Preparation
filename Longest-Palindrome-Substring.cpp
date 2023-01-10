/* https://leetcode.com/problems/longest-palindromic-substring/ */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.size() == 1)
            return s;
        int maxStart = 0, maxCount = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if ((s.size() - i) < maxCount)
                break;
            int j = s.size() - 1;
            while (j > i)
            {
                while (j > i && s[j] != s[i])
                {
                    j--;
                }
                if (j < i)
                    break;
                int i_index = i, j_index = j, count = 0;
                while (i_index < s.size() && j_index >= 0 &&
                       s[i_index] == s[j_index] && i_index <= j_index)
                {
                    count++;
                    i_index++;
                    j_index--;
                }
                if (i_index > j_index)
                {
                    count = (j - i) + 1;
                    if (count >= maxCount)
                    {
                        maxStart = i;
                        maxCount = count;
                        break;
                    }
                }
                j--;
            }
        }
        string output = "";
        for (int i = maxStart; i < maxStart + maxCount; i++)
        {
            output += s[i];
        }
        return output;
    }
};