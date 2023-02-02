# https://leetcode.com/problems/jump-game-ii/

class Solution(object):
    def jump(self, nums):
        jumpsVal = [0] * len(nums)
        for i in range(0, len(nums)):
            j = i + 1
            while j < len(nums) and j <= nums[i] + i:
                jumpsVal[j] = jumpsVal[i] + \
                    1 if jumpsVal[j] == 0 or jumpsVal[j] > jumpsVal[i] + \
                    1 else jumpsVal[j]
                j += 1
        return jumpsVal[-1]
