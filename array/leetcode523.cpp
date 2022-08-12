/**
 * @file leetcode523.cpp
 * @author your name (you@domain.com)
 * @brief Solution to Leetcode 523 Continuous Subarray Sum
 * @version 0.1
 * @date 2022-08-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <vector>
#include <iostream>
#include "utils.hpp"

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) return false;
        int len = nums.size();
        vector<int> sum(len, 0);
        int interval;
        sum[0] = nums[0];
        for (int i = 1; i < len; i++)
        {
            if (nums[i] + nums[i-1] == 0)
                return true;
            sum[i] = sum[i-1] + nums[i];
            if (sum[i] < k)
                continue;
            for (int j = 0; j < i; j++)
            {
                interval = sum[i] - sum[j] + nums[j]; 
                if (interval < k) 
                    continue;
                if (interval % k == 0)
                    return true;
            }
        }
     
        return false;
    }
};

int main()
{
    Solution obj;
    vector<int> nums;
    int k;

    // case 1
    nums = {23, 2, 4, 6, 7};
    k = 6;
    print_array(nums);
    cout << k << endl << obj.checkSubarraySum(nums, k) << endl;

    // case 2
    nums = {23, 2, 6, 4, 7};
    k = 6;
    print_array(nums);
    cout << k << endl << obj.checkSubarraySum(nums, k) << endl;

    // case 3
    nums = {5, 0, 0, 0};
    k = 3;
    print_array(nums);
    cout << k << endl << obj.checkSubarraySum(nums, k) << endl;

    // case 4
    nums = {0, 0};
    k = 1;
    print_array(nums);
    cout << k << endl << obj.checkSubarraySum(nums, k) << endl;

    // case 5
    nums = {5, 0, 4, 0, 0, 2};
    k = 6;
    print_array(nums);
    cout << k << endl << obj.checkSubarraySum(nums, k) << endl;

    return 0;
}