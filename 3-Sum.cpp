/* https://leetcode.com/problems/3sum/ */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        if (nums.size() < 3 || nums[0] > 0)
            return ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int negIndex = i + 1, posIndex = nums.size() - 1;
            bool negChanged = false, posChanged = false;
            while (true)
            {
                if (negIndex >= nums.size() || posIndex < 0 || negIndex == posIndex || nums[posIndex] < 0)
                    break;
                if (negChanged && nums[negIndex] == nums[negIndex - 1])
                {
                    negIndex++;
                }
                else if (posChanged && nums[posIndex] == nums[posIndex + 1])
                {
                    posIndex--;
                }
                else
                {
                    int sum = nums[i] + nums[posIndex] + nums[negIndex];
                    if (sum == 0)
                    {
                        vector<int> key{nums[i], nums[negIndex], nums[posIndex]};
                        ans.push_back(key);
                        posIndex--;
                        posChanged = true;
                        negChanged = false;
                    }
                    else if (sum > 0)
                    {
                        posChanged = true;
                        negChanged = false;
                        posIndex--;
                    }
                    else
                    {
                        posChanged = false;
                        negChanged = true;
                        negIndex++;
                    }
                }
            }
        }
        return ans;
    }
};
