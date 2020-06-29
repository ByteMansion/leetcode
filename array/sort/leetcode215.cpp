/**
 * @brief   Leetcode 215 Kth Largest Element in An Array
 *
 *  Find the kth largest element in an unsorted array. Note that
 *  it is the kth largest element in the sorted order, not the Kth
 *  distinct element.
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include "../../include/utils.hpp"

using namespace std;

class Solution {
public:
    /**
     * 1st solution: use STL algorithm
     *
     * time complexity depends on STL sort algorithm, O(nlogn)
     *
     */
    int findKthLargest(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end(), greater<int>());
        return nums[k - 1];
    }

    /**
     * 2nd solution: use quicksort algorithm
     *
     */
    int findKthLargest2(vector<int>& nums, int k) {
        
    }
};


int main()
{
	vector<int> nums;
	Solution obj;
    int k;

    // case 1
    nums = {3, 2, 1, 5, 6, 4};
    k = 2;
    print_array(nums);
    cout << k << endl;
    cout << obj.findKthLargest(nums, k) << endl;

    // case 2
    nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    k = 4;
    print_array(nums);
    cout << k << endl;
    cout << obj.findKthLargest(nums, k) << endl;

	return 0;
}


