/**
 * @file leetcode75.cpp
 * @brief Leetcode 75 Sort Colors
 * 
 */
#include <vector>
#include "utils.hpp"

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() < 2)
        {
            return;
        }
        int off = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                swap(nums[off], nums[i]);
                off++;
            }
        }
        for (int i = off; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                swap(nums[off], nums[i]);
                off++;
            }
        }
    }
};

int main()
{
    Solution obj;
    vector<int> nums;

    // case 1
    nums = {0};
    print_array(nums);
    obj.sortColors(nums);
    print_array(nums);

    // case 2
    nums = {2, 0, 2, 1, 1, 0};
    print_array(nums);
    obj.sortColors(nums);
    print_array(nums);

    return 0;
}
