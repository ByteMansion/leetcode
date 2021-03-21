/**
 * @file huawei6.cpp
 * @brief 
 * 
 * 连续输入字符串，请按长度为8拆分每个字符串后输出到新的字符串数组
 * 
 */
#include <string>
#include <iostream>

using namespace std;

int main()
{
    string str;
    while(getline(cin, str)) {
        int len = str.length();
        int start = 0;
        int cnt = len / 8;
        int rem = len % 8;
        for(int i = 0; i < cnt; i++) {
            cout << str.substr(start, 8) << endl;
            start += 8;
        }
        if(rem) {
            string cmp(8 - rem, '0');
            cout << str.substr(start, rem) << cmp << endl;
        }

    }

    return 0;
}