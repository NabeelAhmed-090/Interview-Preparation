# https://leetcode.com/problems/merge-sorted-array/

class Solution(object):
    def merge(self, nums1, m, nums2, n):
        for i in range(m, len(nums1)):
            nums1.pop()
        index1 = index2 = 0
        while (index2 < n) and (index1 < len(nums1)):
            if nums2[index2] < nums1[index1]:
                nums1.insert(index1, nums2[index2])
                index2 += 1
            index1 += 1
        for i in range(index2, n):
            nums1.append(nums2[i])
