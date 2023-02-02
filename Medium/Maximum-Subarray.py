# https://leetcode.com/problems/maximum-subarray/

class Solution(object):
    def maxSubArray(self, nums):
        resultSum = []
        resultSum.append(nums[0])
        for i in range(1, len(nums)):
            if nums[i] > resultSum[i-1] + nums[i]:
                resultSum.append(nums[i])
            else:
                resultSum.append(resultSum[i-1] + nums[i])
        return max(resultSum)
