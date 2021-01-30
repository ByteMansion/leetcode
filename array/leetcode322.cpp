/**
 * @brief   Leetcode 322: Coin Change
 * You are given coins of different denominations and a total amount 
 * of money amount. Write a function to compute the fewest number of
 * coins that you need to make up that amount. If that amount of money
 * cannot be made up by any combination of the coins, return -1.
 *
 */
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coin, int amount) {
        // dp[i]: the fewest number of coins that make up amount i
        if(amount == 0) {
            return 0;
        }
        if(amount < 0) {
            return -1;
        }
        //dp[i] = min(dp[i-coin[i]]+1)
        // at most amount coins, amount+1 means INF
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++) {
            for(int j = 0; j < coin.size(); j++) {
                if(i - coin[j] < 0) {
                    continue;
                }
                dp[i] = min(dp[i-coin[j]] + 1, dp[i]);
            }
        }
        if(dp[amount] == amount+1) {
            return -1;
        }

        return dp[amount];
    }

};

int main()
{
    Solution obj;

    vector<int> coin = {1, 2, 5};
    int amount = 11;
    cout << obj.coinChange(coin, amount) << endl;


    return 0;
}
