/**
 * @brief   Leetcode 53 Maximum Subarray
 * Given an integer array nums, find the contiguous subarray
 * (containing at least one number) which has the largest sum 
 * and return its sum.
 *
 */
#include "../include/utils.hpp"
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @brief 1st solution: Dynamic Programming
     * 
     * @param nums 
     * @return int 
     */
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int curSum = 0;
        for(int i = nums.size()-1; i >= 0; i--) {
            curSum += nums[i];
            if(maxSum < curSum) {
                maxSum = curSum;
            }
            if(curSum < 0) {
                curSum = 0;
            }
        }
        return maxSum;
    }

    /**
     * @brief 2nd solution: Divide and Conquer
     * 
     * @param nums 
     * @return int 
     */
    int maxSubArray2(vector<int> &nums)
    {
        int n = nums.size();
        return maxSubArrayHelper(nums, 0, n - 1);
    }

private:
    int maxSubArrayHelper(vector<int> &nums, int lIdx, int rIdx)
    {
        if (lIdx == rIdx)
        {
            return nums[lIdx];
        }
        int mIdx = lIdx + (rIdx - lIdx) / 2;
        int maxLeftSum = maxSubArrayHelper(nums, lIdx, mIdx);
        int maxRightSum = maxSubArrayHelper(nums, mIdx + 1, rIdx);
        int maxAcrossSum = maxAcrossSubArray(nums, lIdx, mIdx, rIdx);
        return max(maxAcrossSum, max(maxLeftSum, maxRightSum));
    }
    int maxAcrossSubArray(vector<int> &nums, int lIdx, int mIdx, int rIdx)
    {
        int sum = nums[mIdx];
        int lLargest = sum;
        for (int i = mIdx - 1; i >= lIdx; i--)
        {
            sum += nums[i];
            if (lLargest < sum)
            {
                lLargest = sum;
            }
        }
        sum = nums[mIdx + 1];
        int rLargest = sum;
        for (int i = mIdx + 2; i <= rIdx; i++)
        {
            sum += nums[i];
            if (rLargest < sum)
            {
                rLargest = sum;
            }
        }
        return max(lLargest + rLargest, max(lLargest, rLargest));
    }
};


int main()
{
    vector<int> nums;
    Solution obj;
    int result;

    // case 1
    nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    result = obj.maxSubArray(nums);
    print_array(nums);
    cout << "Maximum sum: " << result << endl;

    // case 2
    nums = {-1, -2, -3, -4};
    result = obj.maxSubArray(nums);
    print_array(nums);
    cout << "Maximum sum: " << result << endl;

    // case 3
    nums = {0};
    result = obj.maxSubArray(nums);
    print_array(nums);
    cout << "Maximum sum: " << result << endl;

    return 0;
}

