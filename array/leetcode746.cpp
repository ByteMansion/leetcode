/**
 * @brief   Leetcode 746 Min Cost Climbing Stirs
 *
 * On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).
 * Once you pay the cost, you can either climb one or two steps. You need to find minimum
 * cost to reach the top of the floor, and you can either start from the step with index 0,
 * or the step with index 1.
 *
 * Note:
 * 1. cost will have a length in the range [2, 1000].
 * 2. Every cost[i] will be an integer in the range [0, 999].
 */

#include "utils.hpp"
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    /**
     * 1st solution: dynamic programming
     *
     * this is bottom-up method.
     * space complexity: O(n)
     * time complexity: O(n)
     */
    int minCostClimbingStairs(vector<int>& cost) {
        // the length of cost is greater than 2, following statements
        // is unnecessary.
        if(cost.size() < 2) {
            return 0;
        }

        size_t n = cost.size();
        // dp[i]: the min cost when climbing i-th stirs
        vector<int> dp(n+1, 0);

        // base value
        dp[0] = 0;
        dp[1] = 0;

        // dp[n] = min(dp[n-1]+cost[n-1], dp[n-2]+cost[n-2])
        for(int i = 2; i <= n; i++) {
            dp[i] += min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }

        return dp[n];
    }
    /**
     * 2nd solution: dynamic programming
     *
     * this is bottom-up method.
     * 1st solution can be optimized in time complexity.
     * space complexity: O(1)
     * time complexity: O(n)
     */
    int minCostClimbingStairs2(vector<int>& cost) {
        if(cost.size() < 2) {
            return 0;
        }

        size_t n = cost.size();
        int pre = 0;
        int prepre = 0;
        int cur = 0;

        for(int i = 2; i <= n; i++) {
            cur = min(pre + cost[i-1], prepre + cost[i-2]);
            prepre = pre;
            pre = cur;
        }

        return cur;
    }

    /**
     * 3nd solution: dynamic programming
     *
     * this is bottom-up method.
     * space complexity: O(n)
     * time complexity:O(n)
     */
    int minCostClimbingStairs3(vector<int>& cost) {
        if(cost.size() < 2) {
            return 0;
        }

        size_t n = cost.size();

        // dp[i]: the final cost of climbing to the top from step i 
        vector<int> dp(n+1, 0);

        // base
        dp[n] = 0;
        dp[n-1] = cost[n-1];

        // dp[i] = cost[i] + min(dp[i+1], dp[i+2])
        for(int i = n-2; i >= 0; i--) {
            dp[i] = cost[i] + min(dp[i+1], dp[i+2]);
        }

        return min(dp[0], dp[1]);
    }
};

int main()
{
    Solution object;
    vector<int> cost;
    int result;

    // case 1
    cost = {10, 15, 20};
    result = object.minCostClimbingStairs3(cost);
    cout << result << endl;

    // case 2
    cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    result = object.minCostClimbingStairs3(cost);
    cout << result << endl;

    return 0;
}
