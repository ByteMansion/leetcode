/**
 * @file leetcode435.cpp
 * 
 * @brief Leetcode 435 Non-overlapping Intervals
 * 
 * Given a collection of intervals, find the minimum number of 
 * intervals you need to remove to make the rest of the intervals non-overlapping.
 */
#include "utils.hpp"

using namespace std;

class Solution {
public:
    /**
     * Solution: Sorting and then traverse all elements
     * @note if not use reference in lamda expression in sorting, this solution would exceed time limit. 
     */
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int result = 0;
        sort(intervals.begin(), intervals.end(),
             [](auto& s1, auto& s2) { return s1[1] < s2[1]; });

        #if 0
        print_2d_array(intervals);
        #endif

        int prev = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] < prev) {
                result++;
            } else {
                prev = intervals[i][1];
            }
        }
        return result;
    }

};

int main()
{
    Solution obj;
    vector<vector<int>> intervals;

    // case 1
    intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    print_2d_array(intervals);
    cout << obj.eraseOverlapIntervals(intervals) << endl;

    // case 2
    intervals = {{1, 2}, {1, 2}, {1, 2}};
    print_2d_array(intervals);
    cout << obj.eraseOverlapIntervals(intervals) << endl;

    // case 3
    intervals = {{1,11}, {2, 12}, {11, 22}, {1, 100}};
    print_2d_array(intervals);
    cout << obj.eraseOverlapIntervals(intervals) << endl;

    return 0;
}