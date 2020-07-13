/**
 * @brief   Leetcode 350 Intersection of Two Arrays II
 *  Given two arrays, write a function to compute their intersection.
 *
 *  Note:
 *  - Each element in the result should appear as many times as it shows in both arrays.
 *  - The result can be in any order.
 */

#include "../include/utils.hpp"
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> results;
        auto size1 = nums1.size();
        auto size2 = nums2.size();
        if(size1 >= size2) {
            intersectHelper(nums1, nums2, results);
        } else {
            intersectHelper(nums2, nums1, results);
        }
        return results;
    }
private:
    void intersectHelper(vector<int>& lnums, vector<int>& snums,
                         vector<int>& results) {
        map<int, int> numToCount;
        for(auto ele: lnums) {
            numToCount[ele]++;
        }
        for(auto ele: snums) {
            if(numToCount[ele]) {
                numToCount[ele]--;
                results.push_back(ele);
            }
        }
    }
};


int main()
{
    Solution obj;
    vector<int> nums1;
    vector<int> nums2;
    vector<int> results;

    // case 1
    nums1 = {1, 2, 3, 2, 1};
    nums2 = {2, 2};
    results = obj.intersect(nums1, nums2);
    print_array(nums1);
    print_array(nums2);
    print_array(results);


    return 0;
}
