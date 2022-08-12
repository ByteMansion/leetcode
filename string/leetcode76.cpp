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
#include "utils.hpp"

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length()) {
            return "";
        }
        int foundCnt = 0;
        int lIdx = 0;
        int minLen = INT_MAX;
        string res = "";
        // construct dictionary
        unordered_map<char, int> mCh2Cnt;
        for(auto ch: t) {
            mCh2Cnt[ch] += 1;
        }

        for(int i = 0; i < s.length(); i++) {
            char c = s[i];
            if(mCh2Cnt.find(c) == mCh2Cnt.end()) {
                continue;
            }
            if(mCh2Cnt[c]-- > 0) {
                foundCnt++;
            }
            if(foundCnt == t.length()) {
                while(lIdx <= i) {
                    if(mCh2Cnt.find(s[lIdx]) == mCh2Cnt.end()){
                        lIdx++;
                    } else if(mCh2Cnt[s[lIdx]] < 0) {
                        mCh2Cnt[s[lIdx]]++;
                        lIdx++;
                    } else {
                        break;
                    }
                }
                int len = i - lIdx + 1;
                if(len < minLen) {
                    minLen = len;
                    res = s.substr(lIdx, minLen);
                }
            }
            
        }
        return res;
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

