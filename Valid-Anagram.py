# https://leetcode.com/problems/valid-anagram/

class Solution(object):
    def check(self, s1, s2):
        for i in s1:
            if s1.count(i) != s2.count(i):
                return False
        return True

    def isAnagram(self, s, t):
        if len(s) == 0 or len(t) == 0:
            return False
        return self.check(s, t) if len(s) > len(t) else self.check(t, s)
