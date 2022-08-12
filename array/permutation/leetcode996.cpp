/**
 * @brief   Leetcode 996 Number of Squareful Arrays
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
#include <cmath>
#include "utils.hpp"

using namespace std;

class Solution {
private:
    bool isSquare(const int value,
                  unordered_map<int, bool>& squareMap) {
        if(squareMap.find(value) != squareMap.end()) {
            return squareMap[value];
        }
#if 0
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
#endif
        int square = (int)(sqrt(value) + 0.5);
        if(square * square == value) {
            squareMap[value] = true;
        } else {
            squareMap[value] = false;
        }
        return squareMap[value];
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

    bool isSquareful(const int x, const int y) {
        int s = (int)sqrt(x + y);
        return (s * s == x + y);
    }
    void dfs(vector<int>& nums, vector<int>& curr, vector<int>& used, int& result) {
        if(curr.size() == nums.size()) {
            result++;
            return;
        }

        for(size_t index = 0; index < nums.size(); index++) {
            if(used[index]) {
                continue;
            }
            // avoid duplicate calculation
            if(index > 0 && !used[index - 1] && nums[index] == nums[index - 1]) {
                continue;
            }
            // invalid pair 
            if(!curr.empty() && !isSquareful(curr.back(), nums[index])) {
                continue;
            }

            used[index] = 1;
            curr.push_back(nums[index]);
            dfs(nums, curr, used, result);
            used[index] = 0;
            curr.pop_back();
        }
    }

public:
    /**
     * @brief   1st solution is a simple and brute-force method, but time limit exceeded.
     * optimization 1: increase space complexity to save squareful results
     *                 to avoid duplicate calculation;
     * optimization 2: same as the 1st solution, but use math lib to
     *                 check if squareful 
     * time complexity: O(n * logn * n!), n is the length of array
     * space complexity: O(n), n is the length of array
     */
    int numSquarefulPerms(vector<int>& A) {
        unordered_map<int, bool> squareMap; // 1st optimization
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

    /**
     * @brief   2nd solution uses DFS to get all results
     *
     * time complexity: O(n!), n is the length of array
     * space complexity: O(n), n is the length of array
     */
    int numSquarefulPerms2(vector<int>& A) {
        sort(A.begin(), A.end());

        vector<int> curr;
        vector<int> used(A.size(), 0);
        int result = 0;
        dfs(A, curr, used, result);

        return result;
    }

    /**
     * @brief   3rd solution use DP to log mediate result
     *
     * time complexity: O(n^2 * 2^n)
     * space complexity: O(2^n)
     * dp[s][i] := # of ways to reach state s (binary mask of nodes visited) that ends with node i
     * dp[s | (1 << j)][j] += dp[s][i] if g[i][j]
     */
    int numSquarefulPerms3(vector<int>& A) {
        sort(A.begin(), A.end());

        const size_t n = A.size();
        // square[i][j] == 1 if A[i] + A[j] is Squareful
        vector<vector<int>> square(n, vector<int>(n, 0));
        // dp[i][j] := # of ways to reach state i with ending node j
        vector<vector<int>> dp(1 << n, vector<int>(n, 0));

        // init array square[i][j]
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                if(isSquareful(A[i], A[j])) {
                    square[i][j] = 1;
                }
            }
        }

        // only the first counts for duplicate elements
        for(int i = 0; i <  n; i++) {
            if(i == 0 || A[i] != A[i - 1]) {
                dp[1 << i][i] = 1;
            }
        }

        for(int s = 0; s < (1 << n); s++) {
            for(int i = 0; i < n; i++) {
                if(!dp[s][i]) {
                    continue;
                }
                for(int j = 0; j < n; j++) {
                    // not squareful
                    if(!square[i][j]) {
                        continue;
                    }
                    // have been masked in position (1 << j)
                    if(s & (1 << j)) {
                        continue;
                    }
                    // only the first element will be used as destination for duplicates
                    if(j > 0 && !(s & (1 << (j-1))) && A[j - 1] == A[j]) {
                        continue;
                    }
                    dp[s|(1 << j)][j] += dp[s][i];
                }
            }
        }

        int result = 0;
        for(int i = 0; i < n; i++) {
            result += dp[(1 << n) - 1][i];
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
    result = object.numSquarefulPerms3(nums);
    cout << result << endl;

    nums = {1, 1, 1};
    print_array(nums);
    result = object.numSquarefulPerms3(nums);
    cout << result << endl;

    nums = {2, 2, 2};
    print_array(nums);
    result = object.numSquarefulPerms3(nums);
    cout << result << endl;

    // 1st solution could get correct result, but time limit exceeded
    // for this test case.
    nums = {89, 72, 71, 44, 50, 72, 26, 79, 33, 27, 84};
    print_array(nums);
    result = object.numSquarefulPerms3(nums);
    cout << result << endl;

    return 0;
}
