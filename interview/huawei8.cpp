/**
 * @file huawei8.cpp
 * 
 * @brief 
 *  输入一个长度为 6 的数组，输出这 6 个数字能表示的最大时间（24 小时制）。
 *  如果不能组成一个 24 小时制的时间输出 invalid。
 * 
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void getMaxNum(vector<int>& nums, vector<int>& results, int idx, int up)
{
    for(int i = 5; i >= 0; i--) {
        if(nums[i] != -1 && nums[i] <= up) {
            results[idx] = nums[i];
            nums[i] = -1;
            break;
        }
    }
}
string convertIntoString(vector<int> results)
{
    string str = "";
    for(int i = 0; i < 6; i++) {
        if(results[i] == -1) {
            str = "invalid";
            break;
        }
        if(i == 1 || i == 3) {
            str += to_string(results[i]) + ":";
            continue;
        }
        str += to_string(results[i]);
    }
    return str;
}
string getMaxTime(string& str)
{
    vector<int> nums;
    for(auto& ch: str) {
        if(ch >= '0' && ch <= '9') {
            nums.push_back(ch - '0');
        }
    }
    sort(nums.begin(), nums.end());
    vector<int> results(6, -1);
    for(int i = 0; i < 6; i++) {
        if(i == 0) {
            getMaxNum(nums, results, i, 2);
        } else if(i == 1) {
            if(results[0] == 2) {
                getMaxNum(nums, results, i, 3);
            } else {
                getMaxNum(nums, results, i, 9);
            }
        } else if(i == 2 || i == 4) {
            getMaxNum(nums, results, i, 5);
        } else {
            getMaxNum(nums, results, i, 9);
        }
    }
    return convertIntoString(results);
}


int main()
{
    string str;
    
    // case 1
    str = "[0,2,6,5,7,3]";  // output: 23:57:06
    cout << getMaxTime(str) << endl;

    // case 2
    str = "[9,2,6,5,7,9]";
    cout << getMaxTime(str) << endl;

    return 0;
}