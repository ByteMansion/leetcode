/**
 * @file leetcode347.cpp
 * 
 */

#include "utils.hpp"

struct Element {
    int num;
    int fre;

    Element(int n, int f): num(n), fre(f) {}
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mNumToFre;
        for(auto& num: nums) {
            if(mNumToFre.find(num) == mNumToFre.end()) {
                mNumToFre[num] = 1;;
                continue;
            }
            mNumToFre[num]++;
        }
        vector<Element> newNum;
        for(auto mNF: mNumToFre) {
            newNum.push_back(Element(mNF.first, mNF.second));
        }
        sort(newNum.begin(), newNum.end(),
             [](auto n1, auto n2) { return n1.fre > n2.fre; });
        vector<int> results;
        for(int i = 0; i < k; i++) {
            results.push_back(newNum[i].num);
        }
        return results;
    }
};
int main()
{
    Solution obj;
    vector<int> nums;
    int k;
    vector<int> results;

    // case 1
    nums = {1, 1, 1, 2, 2, 3};
    print_array(nums);
    k = 2;
    results = obj.topKFrequent(nums, k);
    print_array(results);

    // case 2
    nums = {1, 2};
    print_array(nums);
    k = 2;
    results = obj.topKFrequent(nums, k);
    print_array(results);

    return 0;
}