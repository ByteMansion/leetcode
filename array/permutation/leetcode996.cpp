/**
 * @brief   Number of Squareful Arrays
 *
 * Given an array A of non-negative integers, the array is squareful 
 * if for every pair of adjacent elements, their sum is a perfect square.
 * Return the number of permutations of A that are squareful.
 * Two permutations A1 and A2 differ if and only if there is some index i such that A1[i] != A2[i].
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "../../include/utils.hpp"

using namespace std;

class Solution {
private:
    bool isSquare(const int value,
                  unordered_map<int, bool>& squareMap) {
        if(squareMap.find(value) != squareMap.end()) {
            return squareMap[value];
        }
        int left = 0;
        int right = value;
        while(left+1 < right) {
            int mid = (left + right) / 2;
            if(mid * mid > value) {
                right = mid;
            } else if(mid * mid < value) {
                left = mid;
            } else {
                squareMap[value] = true;
                return true;
            }
        }
        if(left * left == value) {
            squareMap[value] = true;
            return true;
        }
        if(right * right == value) {
            squareMap[value] = true;
            return true;
        }

        squareMap[value] = false;
        return false;
    }
    bool isSquareful(vector<int>& nums, unordered_map<int, bool>& squareMap) {
        for(size_t index = 0; index < nums.size() - 1; index++) {
            int sum = nums[index] + nums[index+1];
            if(!isSquare(sum, squareMap)) {
                return false;
            }
        }
        return true;
    }

    size_t nextPermutation(vector<int>& nums,
                           int& result,
                           unordered_map<int, bool>& squareMap) {
        size_t pivot = nums.size() - 1;
        while(pivot > 0) {
            if(nums[pivot] <= nums[pivot-1]) {
                pivot--;
            } else {
                break;
            }
        }
        if(pivot == 0) {
            return pivot;
        }

        size_t eIdx;
        for(size_t index = nums.size()-1; index >= pivot; index--) {
            if(nums[index] > nums[pivot-1]) {
                eIdx = index;
                break;
            }
        }
        swap(nums[eIdx], nums[pivot-1]);
        sort(nums.begin()+pivot, nums.end());
        if(isSquareful(nums, squareMap)) {
            result++;
        }
        return pivot;
    }
public:
    // time limit exceeded for some cases
    int numSquarefulPerms(vector<int>& A) {
        if(A.empty()) {
            return 0;
        }
        unordered_map<int, bool> squareMap;
        if(A.size() == 1) {
            if(isSquareful(A, squareMap)) {
                return 1;
            } else {
                return 0;
            }
        }
        int result = 0;
        sort(A.begin(), A.end());
        if(isSquareful(A, squareMap)) {
            result++;
        }
        size_t pivot = A.size() - 1;
        while(pivot > 0) {
            pivot = nextPermutation(A, result, squareMap);
        }

        return result;
    }

};

int main()
{
    Solution object;
    vector<int> nums;
    int result = 0;

    nums = {1, 17, 8};
    print_array(nums);
    result = object.numSquarefulPerms(nums);
    cout << result << endl;

    nums = {1, 1, 1};
    print_array(nums);
    result = object.numSquarefulPerms(nums);
    cout << result << endl;

    nums = {2, 2, 2};
    print_array(nums);
    result = object.numSquarefulPerms(nums);
    cout << result << endl;

    // 1st solution could get correct result, but time limit exceeded
    // for this test case.
    nums = {89, 72, 71, 44, 50, 72, 26, 79, 33, 27, 84};
    print_array(nums);
    result = object.numSquarefulPerms(nums);
    cout << result << endl;

    return 0;
}