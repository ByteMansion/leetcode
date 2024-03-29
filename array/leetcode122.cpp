/**
 * @brief   Leetcode 122 Best Time to Buy and Sell Stock II
 * You are given an array prices where prices[i] is the price of a 
 * given stock on the ith day.
 * 
 * Find the maximum profit you can achieve. You may complete as many 
 * transactions as you like (i.e., buy one and sell one share of the 
 * stock multiple times).
 * 
 * Note: You may not engage in multiple transactions simultaneously 
 * (i.e., you must sell the stock before you buy again).
 */
#include "utils.hpp"
#include <vector>

class Solution
{
public:
    /**
     * @brief   greedy method
     *  time complexity: O(n)
     *  space complexity: O(1)
     * 
     * @param prices 
     * @return int 
     */
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 1) {
            return 0;
        }
        int lIdx = 0, rIdx = 0, total = 0;
        for (int i = 1; i < n; i++)
        {
            if (prices[i] <= prices[i - 1]) {
                if (rIdx != lIdx) {
                    total += prices[rIdx] - prices[lIdx];
                }
                lIdx = i;
            }
            rIdx = i;
        }
        if (rIdx != lIdx) {
            total += prices[rIdx] - prices[lIdx];
        }
        return total;
    }
    /**
     * @brief greedy method
     *  time complexity: O(n)
     *  space complexity: O(n)
     * 
     * @param prices 
     * @return int 
     */
    int maxProfit2(vector<int> &prices)
    {
        if (prices.size() < 2)
        {
            return 0;
        }
        int len = prices.size();
        vector<int> change;
        for (int i = 1; i < len; i++)
        {
            change.push_back(prices[i] - prices[i - 1]);
        }
        int result = 0;
        for (int i = 0; i < len - 1; i++)
        {
            if (change[i] > 0)
            {
                result += change[i];
            }
        }
        return result;
    }
};

int main()
{
    vector<int> prices;
    Solution obj;
    int result;

    // case 1
    prices = {7, 1, 5, 3, 6, 4};
    print_array(prices);
    result = obj.maxProfit(prices);
    cout << result << endl;

    // case 2
    prices = {7, 6, 5, 3, 2, 1};
    print_array(prices);
    result = obj.maxProfit(prices);
    cout << result << endl;

    return 0;
}
