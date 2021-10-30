/**
 * @brief Leetcode 33 Search in Rotated Sorted Array
 * 
 */
#include "../include/utils.hpp"

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;

        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                if (nums[mid] < nums[l] && target >= nums[l])
                    r = mid;
                else
                    l = mid;
            } else {
                if (nums[mid] > nums[r] && target <= nums[r])
                    l = mid;
                else
                    r = mid;
            }
        }
        if (nums[l] == target)
            return l;
        if (nums[r] == target)
            return r;
        return -1;
    }
};

int main()
{
    Solution obj;
    vector<int> nums;

    // case 1
    nums = {4, 5, 6, 7, 0, 1, 2};
    print_array(nums);
    cout << "Find 4, result is " << obj.search(nums, 4) << endl;
    cout << "Find 7, result is " << obj.search(nums, 7) << endl;
    cout << "Find 0, result is " << obj.search(nums, 0) << endl;

    // case 2
    nums = {5, 1, 2, 3};
    print_array(nums);
    cout << "Find 5, result is " << obj.search(nums, 5) << endl;
    cout << "Find 7, result is " << obj.search(nums, 7) << endl;
    cout << "Find 0, result is " << obj.search(nums, 0) << endl;

    // case 3
    nums = {1, 2, 3, 5};
    print_array(nums);
    cout << "Find 5, result is " << obj.search(nums, 5) << endl;
    cout << "Find 7, result is " << obj.search(nums, 7) << endl;
    cout << "Find 1, result is " << obj.search(nums, 1) << endl;

    return 0;
}