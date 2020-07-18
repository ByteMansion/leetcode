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
     * - time complexity: O(n^3)
     * - space complexity: O(1)
     */
    string longestPalindrome(string s) {
        if(s.length() == 0 || s.length() == 1) {
            return s;
        }

        int mLen = 1;
        int sPos = 0;
        for(int start = 0; start < s.length(); start++) {
            for(int end = start + 1; end < s.length() + 1; end++) {
                // substring index range: [start, end)
                if((end - start > mLen) && isPalindrom(start, end, s)) {
                    mLen = end - start;
                    sPos = start;
                }
            }
        }

        return s.substr(sPos, mLen);
    }

public:
    /**
     * 2nd solution: dynamic programming
     * dp[i][j]: means the string s[i..j] is palindrom or not
     *
     * - time complexity:
     * - space complexity: O(n^2)
     */
    string longestPalindrome2(string s) {
        if(s.length() < 2) {
            return s;
        }

        string result;
        int len = s.length();
        int dp[len][len];
        // init special value
        for(int i = 0; i < len; i++) {
            dp[i][i] = true;
        }

        int maxLen = 1;
        int start = 0;
        for(int j = 1; j < len; j++) {
            for(int i = 0; i < j; i++) {
                if(s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if(j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i+1][j-1];
                    }
                }

                if(dp[i][j] && j-i+1 > maxLen) {
                    maxLen = j-i+1;
                    start = i;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};

int main()
{
    string s;
    Solution obj;

    // case 1
    s = "babad";
    cout << s << endl << obj.longestPalindrome2(s) << endl;

    // case 2
    s = "cbbd";
    cout << s << endl << obj.longestPalindrome2(s) << endl;

    return 0;
}
