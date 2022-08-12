/**
 * @brief   Leetcode 121 Best Time to Buy and Sell Stock
 * Say you have an array for which the ith element is the 
 * price of a given stock on day i.
 *
 * If you were only permitted to complete at most one transaction 
 * (i.e., buy one and sell one share of the stock), design an algorithm 
 * to find the maximum profit.
 *
 * Note that you cannot sell a stock before you buy one.
 */
#include "utils.hpp"
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 1st solution: brute force
     *
     * time complexity: O(n^2)
     * spce complexity: O(1)
     */
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        for(int i = 0; i < prices.size(); i++) {
            for(int j = i+1; j < prices.size(); j++) {
                if(prices[j] - prices[i] > 0) {
                    ret = max(ret, prices[j] - prices[i]);
                }
            }
        }
        return ret;
    }
    /**
     * 2nd solution: dynamic programming
     *
     * time complexity: O(n)
     * space complexity: O(n)
     */
    int maxProfit2(vector<int>& prices)
    {
        vector<int> diff;
        for(int i = 1; i < prices.size(); i++) {
            diff.push_back(prices[i] - prices[i-1]);
        }
        int maxSum =0;
        int curSum = 0;
        for(int j = diff.size()-1; j >= 0; j--) {
            curSum += diff[j];
            if(curSum > maxSum) {
                maxSum = curSum;
            }
            if(curSum < 0) {
                curSum = 0;
            }
        }
        return maxSum;
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
