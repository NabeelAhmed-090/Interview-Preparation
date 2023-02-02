# https://leetcode.com/problems/climbing-stairs/

class Solution(object):
    def climbStairs(self, n):
        a, b = 0, 1
        for i in range(n):
            a, b = b, a + b
        return b
