/* https://leetcode.com/problems/median-of-two-sorted-arrays/ */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void updateArray(vector<double> &result, vector<int> &nums, int index)
    {
        for (int i = index; i < nums.size(); i++)
            result.push_back(nums[i]);
    }
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<double> mergeArray;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
            {
                mergeArray.push_back(nums1[i]);
                i++;
            }
            else
            {
                mergeArray.push_back(nums2[j]);
                j++;
            }
        }
        if (i < nums1.size())
            updateArray(mergeArray, nums1, i);
        else if (j < nums2.size())
            updateArray(mergeArray, nums2, j);
        i = mergeArray.size() / 2;
        if (mergeArray.size() % 2 == 0)
        {
            return (mergeArray[i] + mergeArray[i - 1]) / 2;
        }
        else
            return mergeArray[i];
    }
};