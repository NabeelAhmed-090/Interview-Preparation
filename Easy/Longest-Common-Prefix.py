# https://leetcode.com/problems/longest-common-prefix/

class Solution(object):
    def longestCommonPrefix(self, strs):
        output = ""
        index = 0
        for i in strs[0]:
            currChar = i
            for s in strs:
                if s != strs[0]:
                    if index >= len(s) or currChar != s[index]:
                        return output
            output += currChar
            index += 1
        return output
