/**
 * @brief   Leetcode 315  Count of Smaller Numbers After Self
 * 
 */
#include "utils.hpp"

#include <algorithm>

class Solution {
public:
    /** 
     * solution 1: brute force
     * 
     * time complexity: O(n^2)
     * space complexity: O(1)
     * 
     * Exceeds time limit.
     */
    vector<int> countSmaller(vector<int>& nums)
    {
        if(nums.empty()) {
            return vector<int>{};
        }
        int n = nums.size();
        vector<int> results(n, 0);
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(nums[j] < nums[i]) {
                    results[i]++;
                }
            }
        }
        return results;
    }
    /**
     * solution  2: merge sort
     * 
     * time complexity: O(nlogn)
     * space complexity: O(n)
     * 
     */
    vector<int> countSmaller2(vector<int>& nums)
    {
        if(nums.empty()) {
            return vector<int>{};
        }
        int n = nums.size();
        vector<int> results(n, 0);
        vector< pair<int, int> > org;
        for(int i = 0; i < nums.size(); i++) {
            org.push_back(make_pair(nums[i], i));
        }
        vector< pair<int, int> > tmp(n);
        
        mergesort(org, tmp, results, 0, n - 1);

        return results;
    }
private:
    void mergesort(vector<pair<int, int>>& org, 
                   vector<pair<int, int>>& tmp,
                   vector<int>& results,
                   int l, int r)
    {
        if(l >= r) {
            return;
        }
        int m = l + (r - l) / 2;
        mergesort(org, tmp, results, l, m);
        mergesort(org, tmp, results, m + 1, r);

        int i = l, j = m + 1, p = l;
        while(i <= m && j <= r) {
            if(org[i].first <= org[j].first) {
                results[org[i].second] += j - (m + 1);
                tmp[p].first = org[i].first;
                tmp[p++].second = org[i++].second;
            } else {
                tmp[p].first = org[j].first;
                tmp[p++].second = org[j++].second;
            }
        }
        while(i <= m) {
            results[org[i].second] += j - (m + 1);
            tmp[p].first = org[i].first;
            tmp[p++].second = org[i++].second;
        }
        while(j <= r) {
            tmp[p].first = org[j].first;
            tmp[p++].second = org[j++].second;
        }
        copy(tmp.begin() + l, tmp.begin() + r + 1, org.begin() + l);
    }
};

int main()
{
    vector<int> nums;
    vector<int> results;
    Solution obj;

    // case 1: expectation {2,1,1,0}
    nums = {5, 2, 6, 1};
    print_array(nums);
    results = obj.countSmaller2(nums);
    print_array(results);

    // case 2: expectation {6,2,2,1,0,0,0}
    nums = {15, 2, 6, 1, -1, 9, 10};
    print_array(nums);
    results = obj.countSmaller2(nums);
    print_array(results);

    // case 3: expectation {0}
    nums = {1};
    print_array(nums);
    results = obj.countSmaller2(nums);
    print_array(results);

    return 0;
}