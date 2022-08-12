/**
 * @brief   Leetcode 70 Climbing Stirs
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 * Note: Given n will be a positive integer.
 *
 */
#include "utils.hpp"
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 1st solution: dynamic programming
     *
     * space complexity: O(n)
     */
    int climbStairs(int n) {
        if(n <= 2) {
            return n;
        }
        // dp[i]: # of ways when reaching i steps
        vector<int> dp(n+1, 0);

        // base cases
        dp[1] = 1;
        dp[2] = 2;

        // dp[i] = dp[i-1] + dp[i-2]
        for(int i = 3; i < n+1; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
    /**
     * 2nd solution: dynamic programming
     *
     * this is a optimized one compared with 1st solution.
     * space complexity: O(1)
     */
    int climbStairs2(int n) {
        if(n <= 2) {
            return n;
        }
        // base cases
        int first = 1;
        int second = 2;
        int current = 0;

        // get final result
        for(int i = 3; i < n+1; i++) {
            current = first + second;
            first = second;
            second = current;
        }

        return current;
    }
};

int main()
{
    Solution object;
    int num;

    // case 1
    num = 2;
    cout << object.climbStairs2(num) << endl;

    // case 2
    num = 5;
    cout << object.climbStairs2(num) << endl;

    // case 3
    num = 10;
    cout << object.climbStairs2(num) << endl;

    return 0;
}
