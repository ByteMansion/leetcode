/**
 * @brief Leetcode 540 Single Element in a Sorted Array
 * 
 */
#include "utils.hpp"

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        return singleNonDuplicateHelper2(nums, 0, nums.size() - 1);
    }

private:
    /**
     * Solution 1
     */
    int singleNonDuplicateHelper(vector<int>& nums, int l, int r) {
        int len = r - l + 1;
        if(len == 1) return nums[l];
        if(len == 3) {
            return (nums[l] == nums[l+1]) ? nums[l+2] : nums[l];
        }

        int m = l + (r - l) / 2;
        if(m % 2 == 0) {
            if(nums[m] == nums[m-1]) {
                r = m;
            } else if(nums[m] == nums[m+1]) {
                l = m;
            } else {
                return nums[m];
            }
        } else {
            if(nums[m] == nums[m-1]) {
                l = m + 1;
            } else if(nums[m] == nums[m+1]) {
                r = m - 1;
            } else {
                return nums[m];
            }
        }
     
        return singleNonDuplicateHelper(nums, l, r);
    }
    /**
     * Solution 2
     */
    int singleNonDuplicateHelper2(vector<int>& nums, int l, int r) {
        int m = l + (r - l) / 2;
        while (r - l + 1 > 3) {
            if (nums[m] == nums[m-1]) {
                if ((m - l + 1) % 2) {
                    r = m;
                } else {
                    l = m + 1;
                } 
            } else if (nums[m] == nums[m+1]){
                if ((m - l) % 2) {
                    r = m - 1;
                } else {
                    l = m;
                }
            } else {
                return nums[m];
            }
            m = l + (r - l) / 2;
        }
        
        if (nums[m] == nums[l]) {
            return nums[r];
        }
        return nums[l];
    }
};

int main()
{
    Solution obj;
    vector<int> nums;

    // case 1
    nums = {1, 1, 2, 3, 3, 4, 4};
    print_array(nums);
    cout << "Single Element: " << obj.singleNonDuplicate(nums) << endl;

    // case 2
    nums = {1, 1, 2, 2, 3, 3, 4};
    print_array(nums);
    cout << "Single Element: " << obj.singleNonDuplicate(nums) << endl;

    // case 3
    nums = {1, 1, 2, 2, 3, 3, 4, 4, 5};
    print_array(nums);
    cout << "Single Element: " << obj.singleNonDuplicate(nums) << endl;

    // case 4
    nums = {1, 1, 2, 3, 3, 4, 4, 5, 5};
    print_array(nums);
    cout << "Single Element: " << obj.singleNonDuplicate(nums) << endl;


    return 0;
}