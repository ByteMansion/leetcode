/**
 * @file leetcode912.cpp
 * @brief Leetcode 912 Sort An Array
 * 
 */
#include "utils.hpp"

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> tmp = nums;
        mergeSort(nums, tmp, 0, nums.size() - 1);
        return nums;
    }
    void mergeSort(vector<int>& nums, vector<int>& tmp, int l, int r) {
        if (l >= r) {
            return;
        }
        int m = l + (r - l + 1) / 2;
        mergeSort(nums, tmp, l, m - 1);
        mergeSort(nums, tmp, m, r);
        merge(nums, tmp, l, m, r);
    }
    void merge(vector<int>& nums, vector<int>& tmp, int l, int m, int r) {
        int i = l, j = m;
        int k = l;
        while (i < m && j <= r) {
            if (nums[i] > nums[j]) {
                tmp[k++] = nums[j++];
            } else {
                tmp[k++] = nums[i++];
            }
        }
        while (i < m) {
            tmp[k++] = nums[i++];
        }
        while (j <= r) {
            tmp[k++] = nums[j++];
        }
        while (l <= r) {
            nums[l] = tmp[l];
            l++;
        }
    }
};

int main() {
    vector<int> nums;
    Solution obj;

    // case 1
    nums = {3, 2, 1, 5, 6, 4};
    print_array(nums);
    print_array(obj.sortArray(nums));

    // case 2
    nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    print_array(nums);
    print_array(obj.sortArray(nums));

    return 0;

}