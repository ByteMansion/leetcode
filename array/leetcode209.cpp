/**
 * @brief   Leetcode 209 Minimum Size Subarray Sum
 *
 * Given an array of n positive integers and a positive integer s, 
 * find the minimal length of a contiguous subarray of which 
 * the sum ≥ s. If there isn't one, return 0 instead.
 */

#include "utils.hpp"

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        vector<int> preSum(len+1, 0);
        for(int i = 0; i < len; i++) {
            preSum[i+1] += nums[i] + preSum[i];
        }
        int lIdx = 0;
        int rIdx = 1;
        int minLen = 0;
        while(rIdx < len+1) {
            int sum = preSum[rIdx] - preSum[lIdx];
            if(sum >= s) {  // greater than or equal to target
                minLen = (minLen == 0) ? (rIdx - lIdx) :
                         min(minLen, rIdx - lIdx);
                lIdx++;
                continue;
            }
            rIdx++;
        }
        return minLen;
    }
};

int main()
{
    int s;
    vector<int> nums;
    Solution obj;

    // case 1
    s = 7;
    nums = {2, 3, 1, 2, 4, 3};
    print_array(nums);
    cout << s << endl;
    cout << obj.minSubArrayLen(s, nums) << endl;

    // case 2
    s = 8;
    nums = {2, 3, 1, 2, 4, 4};
    print_array(nums);
    cout << s << endl;
    cout << obj.minSubArrayLen(s, nums) << endl;

    return 0;
}

