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
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if ((m + n) % 2)
        {
            return findKthLargestNum(nums1, 0, m, nums2, 0, n, (m + n) / 2 + 1);
        }
        int res1 = findKthLargestNum(nums1, 0, m, nums2, 0, n, (m + n) / 2);
        int res2 = findKthLargestNum(nums1, 0, m, nums2, 0, n, (m + n) / 2 + 1);
        return 1.0 * (res1 + res2) / 2.0;
    }
private:
    int findKthLargestNum(vector<int>& nums1, int l1, int r1, 
                          vector<int>& nums2, int l2, int r2,
                          int k)
    {
        int len1 = r1 - l1;
        int len2 = r2 - l2;
        if (len1 > len2)
        {
            return findKthLargestNum(nums2, l2, r2, nums1, l1, r1, k);
        }
        if (len1 == 0)
        {
            return nums2[l2 + k - 1];
        }
        if (k == 1)
        {
            return min(nums1[l1], nums2[l2]);
        }
        int m1 = l1 + min(len1, k / 2) - 1;
        int m2 = l2 + min(len2, k / 2) - 1;
        if (nums1[m1] > nums2[m2])
        {
            return findKthLargestNum(nums1, l1, r1, nums2, m2 + 1, r2, k - (m2 - l2 + 1));
        }
        else 
        {
            return findKthLargestNum(nums1, m1 + 1, r1, nums2, l2, r2, k - (m1 - l1 + 1));
        }
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