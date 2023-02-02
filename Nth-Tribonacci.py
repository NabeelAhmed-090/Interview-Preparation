# https://leetcode.com/problems/n-th-tribonacci-number/

class Solution(object):
    def tribonacci(self, n):
        if n == 0:
            return 0
        if n == 1 or n == 2:
            return 1
        Tn = 0
        Tn1 = Tn2 = 1
        for i in range(3, n):
            Tn, Tn1, Tn2 = Tn1, Tn2, Tn+Tn1+Tn2

        return Tn+Tn1+Tn2
