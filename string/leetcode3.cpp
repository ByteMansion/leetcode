/**
 * @brief   Leetcode 3 Longest Substring Without Repeating Characters
 * Given a string s, find the length of the longest substring 
 * without repeating characters.
 */

#include "../include/utils.hpp"
#include <cstring>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) {
            return 0;
        }
        map<char, int> mChToIdx;
        int maxLen = 1;
        int leftIdx = 0;
        for(int idx = 0; idx < s.length(); idx++) {
            char ch = s[idx];
            if(mChToIdx.find(ch) != mChToIdx.end() && mChToIdx[ch] >= leftIdx) {
                leftIdx = mChToIdx[ch] + 1;
            }
            mChToIdx[ch] = idx;
            maxLen = max(idx-leftIdx+1, maxLen);
        }
        return maxLen;
    }
};

int main()
{
    string s;
    Solution obj;

    // case 1
    s = "abcabcbb";
    cout << s << endl;
    cout << obj.lengthOfLongestSubstring(s) << endl;

    // case 2
    s = "bbbbb";
    cout << s << endl;
    cout << obj.lengthOfLongestSubstring(s) << endl;

    // case 3
    s = "pwwkewabc";
    cout << s << endl;
    cout << obj.lengthOfLongestSubstring(s) << endl;

    // case 4
    s = "abba";
    cout << s << endl;
    cout << obj.lengthOfLongestSubstring(s) << endl;

    return 0;
}

