/**
 * @file offer45.cpp
 * @brief Offer 45 把数组排成最小的数
 * 
 * 输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

示例 1:
输入: [10,2]
输出: "102"
示例 2:

输入: [3,30,34,5,9]
输出: "3033459"
 
提示:
0 < nums.length <= 100
说明:
输出结果可能非常大，所以你需要返回一个字符串而不是整数
拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0
 */
#include "utils.hpp"

using namespace std;

class Solution {
public:
    /**
     * @brief In this solution, the most important is to 
     */
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        for(auto ele: nums) {
            strs.push_back(to_string(ele));
        }
        sort(strs.begin(), strs.end(), 
            [](string& s1, string& s2) {return s1 + s2 < s2 + s1; });
        string result;
        for(int i = 0; i < strs.size(); i++) {
            result += strs[i];
        }
        return result;
    }
};

int main()
{
    Solution obj;
    vector<int> nums;
    string str;

    // case 1
    nums = {10, 2};
    print_array(nums);
    cout << obj.minNumber(nums) << endl;

    // case 2
    nums = {3, 30, 34, 312, 5, 9};
    print_array(nums);
    cout << obj.minNumber(nums) << endl;

    return 0;
}