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

