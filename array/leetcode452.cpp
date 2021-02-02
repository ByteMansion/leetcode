/**
 * @file leetcode452.cpp
 *
 * @brief Leetcode 452 Minimum Number of Arrows to Burst Balloons
 */
#include "../include/utils.hpp"

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) {
            return 0;
        }
        sort(points.begin(), points.end(), 
             [](vector<int>& p1, vector<int>& p2) { return p1[1] < p2[1]; });
        
        int result = 1;
        int max_overlap = points[0][1];
        for(int i = 1; i < points.size(); i++) {
            if(max_overlap >= points[i][0]) {
                max_overlap = min(max_overlap, points[i][1]);
                continue;
            }
            max_overlap = points[i][1];
            result++;
        }
        return result;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> points;

    // case 1
    points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    print_2d_array(points);
    cout << obj.findMinArrowShots(points) << endl;

    // case 2
    points = {{1, 2,}, {1, 2}};
    print_2d_array(points);
    cout << obj.findMinArrowShots(points) << endl;

    // case 3
    points = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    print_2d_array(points);
    cout << obj.findMinArrowShots(points) << endl;

    return 0;
}