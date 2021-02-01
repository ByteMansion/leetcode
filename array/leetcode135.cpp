/**
 * @file leetcode135.cpp
 * @brief Leetcode 135 Candy
 * 
 * There are N children standing in a line. Each child is assigned a rating value.
 * 
 * You are giving candies to these children subjected to the following requirements:
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * What is the minimum candies you must give?
 *  
 */
#include "../include/utils.hpp"
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int cnt = ratings.size();
        vector<int> candies(cnt, 1);
        for(int i = 1; i < cnt; i++) {
            if(ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1] + 1;
            }
        }
        for(int i = cnt - 1; i > 0; i--) {
            if(ratings[i-1] > ratings[i] && candies[i-1] <= candies[i]) {
                candies[i-1] = candies[i]+1;
            }
        }
        int sum = 0;
        for(auto cnt: candies) {
            sum += cnt;
        }
        return sum;
    }
};
int main()
{
    Solution obj;
    vector<int> ratings;

    // case 1
    ratings = {1, 0, 2};
    cout << obj.candy(ratings) << endl;

    // case 2
    ratings = {1, 2, 2};
    cout << obj.candy(ratings) << endl;

    // case 3
    ratings = {1, 3, 4, 5, 2};
    cout << obj.candy(ratings) << endl;

    return 0;

}