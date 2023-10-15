/**
 * @brief Leetcode 153 Find Minimum in Rotated Sorted Array
 *        All elements are unique.
 * 
 */

#include "utils.hpp"

class Solution {
public:
    int findMin(vector<int>& nums) {
       int l = 0, r = nums.size() - 1;
       if (nums[l] < nums[r]) {
           return nums[l];
       }

        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if(nums[m] > nums[l] && nums[l] > nums[r]) {
                l = m;
            } else {
                r = m;
            }
        }
        return (nums[l] > nums[r]) ? nums[r] : nums[l];
    }
    /**
     * Solution: A easier method for understanding. 
     */
    int findMin2(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums[0];
        }
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            // not rotated
            if (nums[l] < nums[r]) {
                return nums[l];
            }
            // rotated
            int m = l + (r - l) / 2;
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        return min(nums[r], nums[l]);
    }
};

int main()
{
    Solution obj;
    vector<int> nums;

    // case 1
    nums = {4, 5, 6, 1, 2, 3};
    print_array(nums);
    cout << "The minimum: " << obj.findMin(nums) << endl;
    cout << "The minimum: " << obj.findMin2(nums) << endl;

    // case 2
    nums = {7, 8, 9, 10, 1, 2, 3};
    print_array(nums);
    cout << "The minimum: " << obj.findMin(nums) << endl;
    cout << "The minimum: " << obj.findMin2(nums) << endl;

    // case 3
    nums = {1, 2, 3, 4, 5};
    print_array(nums);
    cout << "The minimum: " << obj.findMin(nums) << endl;
    cout << "The minimum: " << obj.findMin2(nums) << endl;

    return 0;
}