/**
 * @brief   Leetcode 167 Two Sum II
 *  The array is sorted.
 */
#include "utils.hpp"
#include <vector>

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        while(l < r) {
            int sum = numbers[l] + numbers[r];
            if(sum == target) {
                break;
            } else if (sum < target) {
                ++l;
            } else {
                --r;
            }
        }
        return vector<int> {l+1, r+1};
    }
};

int main()
{
    Solution obj;
    vector<int> numbers;

    // case 1
    numbers = {2, 7, 11, 15};
    print_array(obj.twoSum(numbers, 22));

    // case 2
    numbers = {2, 7, 11, 15};
    print_array(obj.twoSum(numbers, 9));

    return 0;
}