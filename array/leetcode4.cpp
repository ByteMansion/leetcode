/**
 * @file leetcode4.cpp
 * @brief Median of Two Sorted Arrays
 * @date 2022-05-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "utils.hpp"

class Solution {
private:
    int helper(vector<int> & nums1, vector<int>& nums2, int k) {
        int l1 = 0, l2 = 0;
        int m = nums1.size(), n = nums2.size();
        while (k > 1 && l1 < m && l2 < n) {
            int m1 = min(m - 1, k / 2 + l1 - 1);
            int m2 = min(n - 1, k / 2 + l2 - 1);
            if (nums1[m1] <= nums2[m2]) {
                k -= m1 - l1 + 1;
                l1 = m1 + 1;
            } else {
                k -= m2 - l2 + 1;
                l2 = m2 + 1;
            }
        }
        if (l1 == m) {
            return nums2[l2 + k - 1];
        }
        if (l2 == n) {
            return nums1[l1 + k - 1];
        }
        return min(nums1[l1], nums2[l2]);
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if ((m + n) % 2) {
            return helper(nums1, nums2, (m + n) / 2 + 1);
        }
        int val1 = helper(nums1, nums2, (m + n) / 2);
        int val2 = helper(nums1, nums2, (m + n) / 2 + 1);
        return 1.0 * (val1 +val2) / 2;
    }
};

int main()
{
    Solution obj;
    vector<int> nums1, nums2;
    double res;

    // case 1
    nums1 = {};
    nums2 = {1};
    std::cout << obj.findMedianSortedArrays(nums1, nums2) << std::endl;
    std::cout << obj.findMedianSortedArrays(nums2, nums1) << std::endl;

    // case 2
    nums1 = {1};
    nums2 = {2, 3, 4, 5, 6};
    std::cout << obj.findMedianSortedArrays(nums1, nums2) << std::endl;
    std::cout << obj.findMedianSortedArrays(nums2, nums1) << std::endl;

    // case 3
    nums1 = {1, 2, 4};
    nums2 = {4, 6, 9, 9};
    std::cout << obj.findMedianSortedArrays(nums1, nums2) << std::endl;
    std::cout << obj.findMedianSortedArrays(nums2, nums1) << std::endl;

    system("pause");
    
    return 0;
}