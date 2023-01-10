/* https://leetcode.com/problems/container-with-most-water/ */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int maxAmount = INT_MIN;
        int maxHeight = height[0] - 1;
        int size = height.size();
        if (size > 0)
        {
            for (int j = size - 1; j > 0; j--)
            {
                int min = height[0] > height[j] ? height[j] : height[0];
                int amount = min * (j - 0);
                if (amount > maxAmount)
                    maxAmount = amount;
            }
            int currentMax = 0;
            for (int i = 1; i < size; i++)
            {
                if (height[i] > height[currentMax])
                {
                    for (int j = size - 1; j > i; j--)
                    {
                        int min = height[i] > height[j] ? height[j] : height[i];
                        int amount = min * (j - i);
                        if (amount > maxAmount)
                        {
                            maxAmount = amount;
                            currentMax = i;
                        }
                    }
                }
            }
        }
        return maxAmount == INT_MIN ? 0 : maxAmount;
    }
};