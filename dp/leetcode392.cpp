/**
 * @brief   Leetcode 392: Is Subsequence
 *
 * Given a string s and a string t, check if s is subsequence of t.
 * You may assume that there is only lower case English letters in both
 * s and t. t is potentially a very long (length ~= 500,000) string, and s
 * is a short string (<=100).
 * A subsequence of a string is a new string which is formed from the
 * original string by deleting some (can be none) of the characters without
 * disturbing the relative positions of the remaining characters.
 * (ie, "ace" is a subsequence of "abcde" while "aec" is not).
 *
 * Follow up:
 * If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B,
 * and you want to check one by one to see if T has its subsequence.
 * In this scenario, how would you change your code?
 */

#include "../include/utils.hpp"
#include <cstring>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * 1st solution: brute force
     */
    bool isSubsequence(string s, string t) {
        if(s.empty() && t.empty()) {
            return true;
        }
        if(s.length() > t.length()) {
            return false;
        }

        size_t sIdx = 0;
        for(size_t i = 0; i < t.length(); i++) {
            if(sIdx < s.length() && s[sIdx] == t[i]) {
                sIdx++;
            }
        }
        if(sIdx < s.length()) {
            return false;
        }

        return true;
    }
    /**
     * 2nd solution: create letter look-up table
     */
    bool isSubsequence2(string s, string t) {
        if(s.empty() && t.empty()) {
            return true;
        }
        if(s.length() > t.length()) {
            return false;
        }

        // create a table for positions of lower case letters
        vector<vector<int>> tbl(26, vector<int>{});
        for(size_t idx = 0; idx < t.length(); idx++) {
            tbl[t[idx]-'a'].push_back(idx);
        }

        int pre = -1;
        int cur = 0;
        for(size_t sIdx = 0; sIdx < s.length(); sIdx++) {
            vector<int> pos = tbl[s[sIdx]-'a'];
            if(pos.empty()) {
                return false;
            }
            size_t i;
            for(i = 0; i < pos.size(); i++) {
                if(pos[i] > pre) {
                    pre = cur;
                    cur = pos[i];
                    break;
                }
            }
            if(i == pos.size()) {
                return false;
            }
        }
        return true;
    }

};

int main()
{
    string s;
    string t;
    Solution object;

    // case 1
    s = "abc";
    t = "ahbgtc";
    cout << object.isSubsequence2(s, t) << endl;

    // case 2
    s = "axc";
    t = "ahbgtc";
    cout << object.isSubsequence2(s, t) << endl;

    // case 3
    s = "abcd";
    t = "abcd";
    cout << object.isSubsequence2(s, t) << endl;

    // case 4
    s = "";
    t = "";
    cout << object.isSubsequence2(s, t) << endl;

    return 0;
}
