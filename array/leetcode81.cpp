/**
 * @brief Leetcode 81 Search in Rotated Sorted Array II
 * 
 */

#include "utils.hpp"

class Solution
{
public:
    /**
     * @brief Binary search algorithm cannot decrease the time complexity
     * in worst case. The worst case occurs when we cannot assign the border
     * values according to the left/right border and the middle value.
     * Therefore, the time complexity is O(n).
     * 
     */
    bool search(vector<int> &nums, int target)
    {
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
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