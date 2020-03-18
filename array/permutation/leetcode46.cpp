/**
 * @brief   Permutations
 * Given a collection of distinct integers, return all possible permutations.
 *
 */

#include <vector>
#include <algorithm>
#include <cstdlib>
#include "../../include/utils.hpp"

using namespace std;

class Solution {
private:
    size_t nextPermutation(vector<int>& nums, vector<vector<int>>& results) {
        size_t cnt = nums.size();
        size_t pivot = cnt - 1;
        // find the pivot of this array
        while(pivot > 0) {
            if(nums[pivot] < nums[pivot-1]) {
                pivot--;
            } else {
                break;
            }
        }
        // this array are in descending order
        if(pivot == 0) {
            return pivot;
        }
        // not in descending order
        size_t exInx;
        for(size_t index = cnt-1; index >= pivot; index--) {
            if(nums[index] > nums[pivot-1]) {
                exInx = index;
                break;
            }
        }
        swap(nums[exInx], nums[pivot-1]);
        sort(nums.begin()+pivot, nums.end());
        results.push_back(nums);

        return pivot;
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results(0, vector<int>{});
        if(nums.empty()) {
            return results;
        }

        // sort array and push back first permutation
        sort(nums.begin(), nums.end());
        results.push_back(nums);
        // get permutation one by one until all numbers are in descending order
        size_t pivot = nums.size() - 1;
        while(pivot > 0) {
            pivot = nextPermutation(nums, results);
        }

        return results;
    }

};

int main()
{
    Solution object;
    vector<int> nums;
    vector<vector<int>> results;

    // case 1
    nums = {1,2,3};
    print_array(nums);
    results = object.permute(nums);
    for(size_t index = 0; index < results.size(); index++) {
        print_array(results[index]);
    }

    // case 2
    nums = {1};
    print_array(nums);
    results = object.permute(nums);
    for(size_t index = 0; index < results.size(); index++) {
        print_array(results[index]);
    }


    return 0;
}
