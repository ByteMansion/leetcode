/**
 * @brief Leetcode 34 Find First and Last Position of Element in Sorted Array
 * 
 */
#include "utils.hpp"

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        if (nums.empty())
        {
            return vector<int>{-1, -1};
        }

        return vector<int>{findFirstPos(nums, target), findLastPos(nums, target)};
    }

private:
    int findFirstPos(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        int ret = -1;
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                ret = r = mid;
            } else if (nums[mid] > target) {
                r = mid;
            } else {
                l = mid;
            }
        }
        if (nums[l] == target) {
            return l;
        }
        if (nums[r] == target) {
            return r;
        }
        return ret;
    }
    int findLastPos(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        int ret = -1;
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                ret = l = mid;
            } else if (nums[mid] > target) {
                r = mid;
            } else {
                l = mid;
            }
        }
        if (nums[r] == target) {
            return r;
        }
        if (nums[l] == target) {
            return l;
        }
        return ret;
    }
};

int main()
{
    Solution obj;
    vector<int> nums;
    vector<int> ret;

    // case 1
    nums = {5, 7, 7, 8, 8, 10};
    ret = obj.searchRange(nums, 5);
    print_array(nums);
    print_array(ret); 

    // case 2
    ret = obj.searchRange(nums, 8);
    print_array(ret);

    // case 3
    ret = obj.searchRange(nums, 10);
    print_array(ret);

    // case 4
    ret = obj.searchRange(nums, 6);
    print_array(ret); 

    return 0;
}