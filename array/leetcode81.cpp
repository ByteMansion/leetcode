/**
 * @brief Leetcode 81 Search in Rotated Sorted Array II
 * 
 */

#include "../include/utils.hpp"

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;

        while (l + 1 < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
            {
                return true;
            }
            else if (nums[mid] < target)
            {
                if (nums[mid] < nums[l] && target >= nums[l])
                {
                    r = mid;
                }
                else
                {
                    l = mid;
                }
            }
            else
            {
                if (nums[mid] > nums[r] && target <= nums[r])
                {
                    l = mid;
                }
                else
                {
                    r = mid;
                }
            }
        }
        if (nums[l] == target)
            return true;
        if (nums[r] == target)
            return true;
        return false;
    }
};

int main()
{
    Solution obj;
    vector<int> nums;

    // case 1
    nums = {2, 5, 6, 0, 0, 1, 2};
    print_array(nums);
    cout << "Find 1, result is " << obj.search(nums, 1) << endl;
    cout << "Find 6, result is " << obj.search(nums, 6) << endl;
    cout << "Find 0, result is " << obj.search(nums, 0) << endl;

    // case 2
    nums = {1, 1, 1, 1, 1, 1, 1, 1, 1, 13, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    print_array(nums);
    cout << "Find 13, result is " << obj.search(nums, 13) << endl;
    cout << "Find 7, result is " << obj.search(nums, 7) << endl;

    // case 3
    nums = {1, 0, 1, 1, 1};
    print_array(nums);
    cout << "Find 0, result is " << obj.search(nums, 0) << endl;

    return 0;
}