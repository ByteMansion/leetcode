/**
 * @brief Leetcode 96 Unique Binary Search Trees
 * 
 * Given an integer n, return the number of structurally unique BST's
 * (binary search trees) which has exactly n nodes of unique values from 1 to n.
 * 
 */

#include "../include/utils.hpp"

using namespace std;

class Solution {
public:
    /**
     * @brief Dynamic Programming
     *  Both subtrees of binary search tree are binary search trees.
     *  For binary search tree, the most important characteristic is preorder
     *  traversal of this tree is in increasing order.
     * 
     * @param n 
     * @return int 
     */
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        // the count of binary tree with root node k is dp[k-1] * dp[n-k]
        // dp[n] = sum(dp[k-1] * dp[n-k]), k from 1 to n
        dp[0] = 1; dp[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= i; j++) {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution obj;
    int n;

    // case 1
    n = 3;
    cout << obj.numTrees(n) << endl;

    // case 2
    n = 1;
    cout << obj.numTrees(n) << endl;

    // case 3
    n = 10;
    cout << obj.numTrees(n) << endl;

    return 0;
}