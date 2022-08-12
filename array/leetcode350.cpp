/**
 * @brief   Leetcode 350 Intersection of Two Arrays II
 *  Given two arrays, write a function to compute their intersection.
 *
 *  Note:
 *  - Each element in the result should appear as many times as it shows in both arrays.
 *  - The result can be in any order.
 */

#include "utils.hpp"
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * 1st solution 
     */
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

public:
    /**
     * 2nd solution
     */
    vector<int> intersect2(vector<int>& nums1, vector<int>& nums2) {
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));
        vector<int> results;
        int i = 0;
        int j = 0;
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] == nums2[j]) {
                results.push_back(nums1[i]);
                i++;
                j++;
            } else if(nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return results;
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
    results = obj.intersect2(nums1, nums2);
    print_array(nums1);
    print_array(nums2);
    print_array(results);


    return 0;
}
