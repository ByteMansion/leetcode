/**
 * @brief   Leetcode 47 Permutations II
 *
 * Given a collection of numbers that might contain duplicates,
 * return all possible unique permutations.
 *
 */

#include <vector>
#include <algorithm>
#include "../../include/utils.hpp"

using namespace std;

class Solution {
private:
    size_t nextPermutation(vector<int>& nums,
                           vector<vector<int>>& results) {
        size_t len = nums.size();
        size_t pivot = len - 1;
        // get pivot
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
        // get the smallest number index ranging from
        // pivot to the end
        size_t sIdx;
        for(size_t index = len - 1; index >= pivot; index--) {
            if(nums[index] > nums[pivot-1]) {
                sIdx = index;
                break;
            }
        }
        swap(nums[pivot-1], nums[sIdx]);
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

        for(size_t idx = 0; idx < nums.size(); idx++) {
            if(used[idx] == 1) {
                continue;
            }
            // only the 1st element of duplicates can be used as head of a permutation
            if(idx > 0 && (nums[idx] == nums[idx-1]) && used[idx-1] == 0) {
                continue;
            }

            used[idx] = 1;
            perm.push_back(nums[idx]);
            dfsHelper(nums, used, perm, results);
            used[idx] = 0;
            perm.pop_back();
        }
    }

public:
    /**
     * @brief   1st soluton: swap and then sort
     *
     * time complexity: O(n!*n)
     * space complexity: O(1)
     */
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> results;
        if(nums.size() < 2) {
            results.push_back(nums);
            return results;
        }

        sort(nums.begin(), nums.end());
        results.push_back(nums);

        size_t cnt = nums.size();
        size_t pivot = cnt - 1;
        while(pivot > 0) {
            pivot = nextPermutation(nums, results);
        }
        return results;
    }

    /**
     * @brief   2nd solution: backtracking - DFS
     *
     * time complexity: O(n!)
     * space complexity: O(n)
     */
    vector<vector<int>> permuteUnique2(vector<int>& nums) {
        vector<vector<int>> results;
        if(nums.size() < 2) {
            results.push_back(nums);
            return results;
        }

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

    nums = {1, 1, 1, 1, 1, 1};
    print_array(nums);
    results = object.permuteUnique2(nums);
    cout << results.size() << endl;
    for(auto tmp: results) {
        print_array(tmp);
    }

    nums = {1, 1, 2, 2, 2, 3};
    print_array(nums);
    results = object.permuteUnique2(nums);
    cout << results.size() << endl;
    for(auto tmp: results) {
        print_array(tmp);
    }

    return 0;
}
