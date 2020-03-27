/**
 * @brief   Leetcode 46 Permutations
 *
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

    void dfsHelper(vector<int>& nums, vector<int>& used, vector<int>& perm,
                   vector<vector<int>>& results) {
        if(perm.size() == nums.size()) {
            results.push_back(perm);
            return;
        }

        for(size_t index = 0; index < nums.size(); index++) {
            if(used[index] == 1) {
                continue;
            }
            used[index] = 1;
            perm.push_back(nums[index]);
            dfsHelper(nums, used, perm, results);
            used[index] = 0;
            perm.pop_back();
        }
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

    vector<vector<int>> permute2(vector<int>& nums) {
        vector<vector<int>> results(0, vector<int>{});
        if(nums.empty()) {
            return results;
        }

        // sort array numbers
        sort(nums.begin(), nums.end());

        vector<int> used(nums.size(), 0);
        vector<int> perm;
        dfsHelper(nums, used, perm, results);

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
    results = object.permute2(nums);
    for(size_t index = 0; index < results.size(); index++) {
        print_array(results[index]);
    }

    // case 2
    nums = {1};
    print_array(nums);
    results = object.permute2(nums);
    for(size_t index = 0; index < results.size(); index++) {
        print_array(results[index]);
    }

    // case 3
    nums = {4, 2, 6, 9};
    print_array(nums);
    results = object.permute2(nums);
    for(size_t index = 0; index < results.size(); index++) {
        print_array(results[index]);
    }

    return 0;
}
