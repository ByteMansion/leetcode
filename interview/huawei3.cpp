/**
 * @file huawei3.cpp
 * 
 * @brief
 * 
 * 给定一个包含1-n的数列，我们通过交换任意两个元素给数列重新排序。
 * 求最少需要多少次交换，能把数组排成按1-n递增的顺序，（数组中的元素互不重复）。
 */
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

int getMinSwaps(vector<int>& nums)
{
    vector<int> sortedNums(nums);
    sort(sortedNums.begin(), sortedNums.end());
    map<int, int> mNumToPos;
    for(int i = 0; i < sortedNums.size(); i++) {
        mNumToPos[sortedNums[i]] = i;
    }
    int cnt = 0;  // swap count
    for(int i = 0; i < nums.size(); i++) {
        if(i == mNumToPos[nums[i]]) {
            continue;
        }
        swap(nums[i], nums[mNumToPos[nums[i]]]);
        cnt++;
    }
    return cnt;

}

int main()
{
    vector<int> nums;
    int num;
    while(cin >> num) {
        nums.push_back(num);
    }

    int minCnt = getMinSwaps(nums);
    cout << minCnt << endl;

    return 0;
}