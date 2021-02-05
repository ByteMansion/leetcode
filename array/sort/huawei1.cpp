/**
 * @file huawei1.cpp
 * 明明想在学校中请一些同学一起做一项问卷调查，为了实验的客观性，他先用计算机生成了N个1到1000之间
 * 的随机整数（N≤1000），对于其中重复的数字，只保留一个，把其余相同的数去掉，不同的数对应着不同
 * 的学生的学号。然后再把这些数从小到大排序，按照排好的顺序去找同学做调查。
 * 请你协助明明完成“去重”与“排序”的工作(同一个测试用例里可能会有多组数据，希望大家能正确处理)。
 * 
 * 注：测试用例保证输入参数的正确性，答题者无需验证。测试用例不止一组。
 * 当没有新的输入时，说明输入结束。
 */
#if 0
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> dedupandsort(vector<int> nums) {
    int sIdx = 0;
    vector<int> result;
    int cnt = nums.size();
    while(sIdx < cnt) {
        int eIdx = sIdx + nums[sIdx];
        vector<int> group;
        while(++sIdx <= eIdx) {
            group.push_back(nums[sIdx]);
        }
        sort(group.begin(), group.end());
        for(int idx = 0; idx < group.size(); idx++) {
            if(idx > 0 && group[idx] == group[idx-1]) {
                continue;
            }
            result.push_back(group[idx]);
        }
    }
    return result;
}
int main()
{
    vector<int> nums;
    int n;
    while(cin >> n) {
        nums.push_back(n);
    }
    vector<int> result = dedupandsort(nums);
    for(auto num: result) {
        cout << num << endl;
    }
    return 0;
}
#endif
/**
 * @brief Better solution: use set
 * 
 */
#include <set>
#include <iostream>

using namespace std;


int main()
{
    int n;
    set<int> nums;
    while(cin >> n) {
        nums.insert(n);
    }

    for(auto num: nums) {
        cout << num << endl;
    }
    
    return 0;
}