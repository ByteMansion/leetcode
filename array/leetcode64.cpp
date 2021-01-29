/**
 * @brief Leetcode 64 Minimum Path Sum
 * 
 * Given a m x n grid filled with non-negative numbers, find a path from
 * top left to bottom right, which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 */
#include "../include/utils.hpp"

using namespace std;

class Solution {
public:
    /**
     * @brief Dynamic Programming
     * 
     * @param grid 
     * @return int 
     */
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(columns, 0));
        dp[0][0] = grid[0][0];
        int i, j;
        for(j = 1; j < columns; j++) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }
        for(i = 1; i < rows; i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(i = 1; i < rows; i++) {
            for(j = 1; j < columns; j++) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[rows-1][columns-1];
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> grid;

    // case 1
    grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    print_2d_array(grid);
    cout << obj.minPathSum(grid) << endl;

    // case 2
    grid = {{1, 2, 3}, {4, 5, 6}};
    print_2d_array(grid);
    cout << obj.minPathSum(grid) << endl;

    return 0;
}