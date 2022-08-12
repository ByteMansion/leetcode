/**
 * @file leetcode120.cpp
 * 
 * Given a triangle array, return the minimum path sum from top to bottom.
 * For each step, you may move to an adjacent number of the row below. 
 * More formally, if you are on index i on the current row, you may move to 
 * either index i or index i + 1 on the next row.
 * 
 */
#include "utils.hpp"

using namespace std;

class Solution {
public:
    /**
     * @brief Dynamic Programming
     *  time complexity: O(n^2)
     *  space complexity: O(n^2)
     * 
     * @param triangle 
     * @return int 
     */
    int minimumTotal(vector<vector<int>>& triangle) {
        int height = triangle.size();
        vector<vector<long>> dp(height, vector<long>(height, 0));
        dp[0][0] = triangle[0][0];
 
        for(int r = 1; r < height; r++) {
            for(int i = 0; i <= r; i++) {
                if(i == 0) {
                    dp[r][0] = dp[r-1][0] + triangle[r][0];
                } else if(i == r) {
                    dp[r][i] = dp[r-1][i-1] + triangle[r][i];
                } else {
                    dp[r][i] = min(dp[r-1][i], dp[r-1][i-1]) + triangle[r][i];
                }
            }
        }

        int result = INT_MAX;
        for(auto sum: dp[height-1]) {
            if(sum < result) {
                result = sum;
            }
        }
        return result;
    }
    int minimumTotal2(vector<vector<int>>& triangle) {
        int height = triangle.size();
        vector<int> prev(height, 0);
        vector<int> next(height, 0);
        prev[0] = triangle[0][0];
        for(int r = 1; r < height; r++) {
            for(int i = 0; i <= r; i++) {
                if(i == 0) {
                    next[0] = prev[0] + triangle[r][0];
                } else if(i == r) {
                    next[i] = prev[i-1] + triangle[r][i];
                } else {
                    next[i] = min(prev[i], prev[i-1]) + triangle[r][i];
                }
            }
            prev = next;
        }

        int result = INT_MAX;
        for(auto sum: prev) {
            result = min(sum, result);
        }
        return result;
    }
};

int main() 
{
    Solution obj;
    vector<vector<int>> triangle;

    // case 1
    triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    print_2d_array(triangle);
    cout << obj.minimumTotal2(triangle) << endl;

    // case 2
    triangle = {{-10}};
    print_2d_array(triangle);
    cout << obj.minimumTotal2(triangle) << endl;

    return 0;
}