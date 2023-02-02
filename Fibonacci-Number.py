# https://leetcode.com/problems/fibonacci-number/

class Solution(object):
    def fib(self, n):
        if n == 0:
            return 0
        if n == 1 or n == 2:
            return 1
        curr = prev = 1
        for i in range(3, n):
            curr, prev = curr + prev, curr
        return curr + prev
