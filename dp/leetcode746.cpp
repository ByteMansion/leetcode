/**
 * @brief   Leetcode 746 Min Cost Climbing Stirs
 *
 * On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).
 * Once you pay the cost, you can either climb one or two steps. You need to find minimum
 * cost to reach the top of the floor, and you can either start from the step with index 0,
 * or the step with index 1.
 *
 */

#include "../include/utils.hpp"
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() < 2) {
            return 0;
        }

        size_t n = cost.size();
        cost.push_back(0);
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
};

int main()
{
    Solution object;
    vector<int> cost;
    int result;

    // case 1
    cost = {10, 15, 20};
    result = object.minCostClimbingStairs(cost);
    cout << result << endl;

    // case 2
    cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    result = object.minCostClimbingStairs(cost);
    cout << result << endl;

    return 0;
}
