# https://leetcode.com/problems/permutations-ii/

class Solution(object):
    result = []

    def recur(self, currArr, nums):
        if not nums:
            self.result.append(currArr)
            return
        addValues = []
        for i in range(0, len(nums)):
            if nums[i] not in addValues:
                addValues.append(nums[i])
                self.recur(currArr + [nums[i]], nums[0:i]+nums[i+1:])
            else:
                addValues.append(nums[i])

    def permuteUnique(self, nums):
        del self.result[:]
        if len(nums) == 0 or len(nums) == 1:
            return [nums]
        self.recur([], nums)
        return self.result
