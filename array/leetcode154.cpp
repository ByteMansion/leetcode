/**
 * @brief Leetcode 154 Find Minimum in Rotated Sorted Array II
 * 
 */
#include "../include/utils.hpp"

class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size() - 1;
        if(nums[0] < nums[len]) {
            return nums[0];
        }

        int minVal = nums[0];
        for(int i = 0; i < len; ++i) {
            if(nums[i] > nums[i+1]) {
                minVal = nums[i+1];
                break;
            }
        }
        return minVal;
    }
};

int main()
{
    Solution obj;
    vector<int> nums;

    // case 1
    nums = {6, 6, 7, 8, 1, 2, 4, 6};
    print_array(nums);
    cout << "The minimum: " << obj.findMin(nums) << endl;

    // case 2
    nums = {1, 1, 1, 1, 13, 1, 1, 1};
    print_array(nums);
    cout << "The minimum: " << obj.findMin(nums) << endl;

    // case 3
    nums = {3, 1};
    print_array(nums);
    cout << "The minimum: " << obj.findMin(nums) << endl;
  
    system("pause");
    return 0;
}