/* https://leetcode.com/problems/longest-substring-without-repeating-characters/ */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int longestLength = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int arr[256] = {0}, length = 1;
            arr[int(s[i])] = 1;
            for (int j = i + 1; j < s.size(); j++)
            {
                if (arr[int(s[j])] == 0)
                {
                    arr[int(s[j])] = 1;
                    length++;
                }
                else
                    break;
            }
            if (length > longestLength)
                longestLength = length;
            if (i + longestLength > s.size())
                break;
        }
        return longestLength;
    }
};