/**
 * @brief   Leetcode 665 Non-decreasing Array
 * Given an array nums with n integers, your task is to check 
 * if it could become non-decreasing by modifying at most one element.
 * 
 * We define an array is non-decreasing if nums[i] <= nums[i + 1] 
 * holds for every i (0-based) such that (0 <= i <= n - 2).
 * 
 */
#include "../include/utils.hpp"

class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
        {
            return true;
        }
        int count = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1])
            {
                count++;
                if (i >= 2 && nums[i - 2] > nums[i])
                {
                    nums[i] = nums[i - 1];
                }
                else
                {
                    nums[i - 1] = nums[i];
                }
            }
        }
        return count < 2;
    }
};

int main()
{
    Solution obj;
    vector<int> nums;

    // case 1
    nums = {4, 2, 3};
    print_array(nums);
    cout << obj.checkPossibility(nums) << endl;

    // case 2
    nums = {4, 2, 1};
    print_array(nums);
    cout << obj.checkPossibility(nums) << endl;

    // case 3
    nums = {3, 4, 2, 3};
    print_array(nums);
    cout << obj.checkPossibility(nums) << endl;

    // case 4
    nums = {5, 7, 1, 8};
    print_array(nums);
    cout << obj.checkPossibility(nums) << endl;

    return 0;
}