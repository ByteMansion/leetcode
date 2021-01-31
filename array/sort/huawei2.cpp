/**
 * @file huawei2.cpp
 * 
 * 写出一个程序，接受一个十六进制的数，输出该数值的十进制表示。
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

inline static int hex_to_int(char digit)
{
    if(digit <= '9' && digit >= '0') {
        return digit - '0';
    }
    return 10 + digit - 'A';
}
static int hextodecHelper(string& hex)
{
    int len = hex.length();
    int dec = 0;
    int mul = 1;
    for(int i = len - 1; i > 1; i--) {
        dec += hex_to_int(hex[i]) * mul;
        mul *= 16;
    }
    return dec;
}
vector<string> hextodec(vector<string>& nums)
{
    vector<string> results;
    for(auto hex: nums) {
        int dec = hextodecHelper(hex);
        results.push_back(to_string(dec));
    }
    return results;
}

int main()
{
    string hex;
    vector<string> nums;
    while(cin >> hex) {
        nums.push_back(hex);
    }
    vector<string> results = hextodec(nums);
    for(auto dec: results) {
        cout << dec << endl;
    }

    return 0;
}