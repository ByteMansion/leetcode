/**
 * @brief   Leetcode 76 Minimum Window Substring
 *
 * Given two strings s and t, return the minimum window in s 
 * which will contain all the characters in t. If there is no 
 * such window in s that covers all characters in t, return 
 * the empty string "".
 *
 * Note that If there is such a window, it is guaranteed that 
 * there will always be only one unique minimum window in s.
 */
#include "../include/utils.hpp"

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mChToCnt;
        for(auto ch : t) {
            mChToCnt[ch]++;
        }

        int foundCnt = 0;
        int lIdx = -1;
        int minLen = 0;
        for(int i = 0; i < s.length(); i++) {
            if(mChToCnt[s[i]] == 0) {
                continue;
            }
            if(foundCnt == 0) {
                lIdx = i;
            }
            mChToCnt[s[i]]--;
            foundCnt++;
            if(foundCnt == t.length()) {
                minLen = (minLen == 0) ? (i - lIdx + 1) : min(minLen, i - lIdx + 1);
            }
        }
        if(foundCnt == t.length()) {
            return s.substr(lIdx, minLen);
        }
        return "";
    }
};

int main()
{
    string s;
    string t;
    Solution obj;

    // case 1
    s = "AAAADOBECODEBANC";
    t = "AABC";
    cout << obj.minWindow(s, t) << endl;

    return 0;
}

