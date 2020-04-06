/**
 * @brief   Leetcode 70 Climbing Stirs
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 * Note: Given n will be a positive integer.
 *
 */
#include "../include/utils.hpp"
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) {
            return n;
        }
        // dp[i]: # of ways when reaching i steps
        vector<int> dp(n+1, 0);

        // base case
        dp[1] = 1;
        dp[2] = 2;

        // dp[i] = dp[i-1] + dp[i-2]
        for(int i = 3; i < n+1; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};

int main()
{
    Solution object;
    int num;

    // case 1
    num = 2;
    cout << object.climbStairs(num) << endl;

    // case 2
    num = 5;
    cout << object.climbStairs(num) << endl;

    // case 3
    num = 10;
    cout << object.climbStairs(num) << endl;

    return 0;
}
