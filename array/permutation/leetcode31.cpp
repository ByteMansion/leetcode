/**
 * @brief   Leetcode 31 Next Permutation 
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * If such arrangement is not possible, it must rearrange it as
 * the lowest possible order (ie, sorted in ascending order).
 * The replacement must be in-place and use only constant extra memory.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "../../include/utils.hpp"

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1) {
            return;
        }

        // find pivot of this array
        size_t cnt = nums.size();
        size_t pivot = cnt - 1;
        while(pivot > 0) {
            if(nums[pivot] <= nums[pivot-1]) {
                pivot--;
            } else {
                break;
            }
        }
        // this array is in descending order, so reverse it
        if(pivot == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        // this array is not in descending order
        // find the smallest number larger than nums[pivot-1]
        size_t exInx;
        for(size_t index = cnt-1; index >= pivot; index--) {
            if(nums[index] > nums[pivot-1]) {
                exInx = index;
                break;
            }
        }
        // swap nums[swap] and nums[pivot-1]
        // sort numbers ranges from pivot to cnt
        swap(nums[exInx], nums[pivot-1]);
        sort(nums.begin()+pivot, nums.end());
    }

private:

};

int main()
{
    Solution object;
    vector<int> nums = {7, 9, 3, 6, 5};
    cout << "original array:" << endl;
    print_array(nums);
    object.nextPermutation(nums);
    cout << "next permutation:" << endl;
    print_array(nums);

    nums = {9, 7, 6, 5, 3};
    cout << "original array:" << endl;
    print_array(nums);
    object.nextPermutation(nums);
    cout << "next permutation:" << endl;
    print_array(nums);



    return 0;
}


