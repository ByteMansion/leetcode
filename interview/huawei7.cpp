/**
 * @file huawei7.cpp
 * 
 * 将一个英文语句以单词为单位逆序排放。例如“I am a boy”，逆序排放后为“boy a am I”
 * 所有单词之间用一个空格隔开，语句中除了英文字母外，不再包含其他字符
 * 
 */
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    while(getline(cin, str)) {
        int len = str.length();
        int eIdx = len;
        for(int sIdx = len - 1; sIdx >= 0; sIdx--) {
            if(str[sIdx] == ' ') {
                cout << str.substr(sIdx + 1, eIdx - sIdx - 1) << " ";
                eIdx = sIdx;
            }
        }
        cout << str.substr(0, eIdx) << endl;
    }

    return 0;
}