/**
 * @brief   Leetcode 5: Longest Palindrom Substring
 *
 * Given a string s, find the longest palindromic substring in s.
 * You may assume that the maximum length of s is 1000.
 *
 */

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    bool isPalindrom(int start, int end, string s) {
        while(start < end) {
            if(s[start] != s[end-1]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
public:
    /**
     * 1st solution: brute-force
     *
     *  time complexity: O(n^3)
     */
    string longestPalindrome(string s) {
        if(s.length() == 0 || s.length() == 1) {
            return s;
        }

        int maxLen = 1;
        int sPos = 0;
        for(int start = 0; start < s.length(); start++) {
            for(int end = start + 1; end <= s.length(); end++) {
                // string index: [start, end)
                if(isPalindrom(start, end, s)) {
                    if(maxLen < end - start) {
                        maxLen = end - start;
                        sPos = start;
                    }
                }
            }
        }

        return s.substr(sPos, maxLen);
    }
#if 0
    string longestPalindrome(string s) {
        if(s.length() == 0 || s.length() == 1) {
            return s;
        }

        int start = 0;
        int strLen = s.length();
        /**
          dp[i]: the longest length of the palindrom, whose ending letter is the ith letter, default value is 1
           dp[i] = dp[i-1]+2 if dp[i] == dp[i-dp[i-1]]
           dp[i] = dp[i-1]+1 if dp[i] == dp[i-1]
         */
        vector<int> dp(strLen, 1);
        int maxLen = 1;
        int index;
        for(int i = 1; i < strLen; i++) {
            if(i-dp[i] >= 0 && s[i+1] == s[i-dp[i]]) {
                dp[i+1] = dp[i] + 2;
                index = i - dp[i-1] - 1;
            }
        }

        return s.substr(start, maxLen);

    }
#endif
};

int main()
{
    string s;
    Solution obj;

    // case 1
    s = "babad";
    cout << obj.longestPalindrome(s) << endl;

    // case 2
    s = "cbbd";
    cout << obj.longestPalindrome(s) << endl;

    return 0;
}
