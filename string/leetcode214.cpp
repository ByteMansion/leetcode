/**
 * @brief Leetcode 214 Shortest Palindrome
 *        You are given a string s. You can convert s to a palindrome 
 *        by adding characters in front of it.
 *        Return the shortest palindrome you can find by performing this transformation.
 */
#include "utils.hpp"

class Solution {
private:
    bool isPalindrome(string s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
public:
    /**
     * Solution 1: brute force
     * The solution is to find the palindrome substring with the maximum length. 
     * Cannot pass for exceeding time limit.
     * 
     * time complexity: O(n^2)
     * space complexity: O(1)
     */
    string shortestPalindrome(string s) {
        int len = s.length();
        if (len <= 1) {
            return s;
        }
        string res;
        int bound = 0;
        for (int i = 1; i < len; i++) {
            if (isPalindrome(s, 0, i)) {
                bound = i;
            }
        }
        if (bound == len - 1) {
            return s;
        }
        res = s.substr(bound + 1, len - bound - 1);
        reverse(res.begin(), res.end());
        return res + s;
    }
    /**
     * Solution 2: KMP algorithm
     * 
     * time complexity: O(n)
     * space complexity: O(n)
     */
    string shortestPalindrome2(string s) {
        int len = s.length();
        if (len <= 1) {
            return s;
        }
        /* compute prefix */
        vector<int> prefix(len, -1);
        int pIdx = -1;
        for (int sIdx = 1; sIdx < len; sIdx++) {
            while (pIdx >= 0 && s[pIdx + 1] != s[sIdx]) {
                pIdx = prefix[pIdx];
            }
            if (s[pIdx + 1] == s[sIdx]) {
                pIdx += 1;
            }
            prefix[sIdx] = pIdx;
        }
        /* find the longest palindrome, search string reversely */
        int match = -1;
        for (int i = len - 1; i >= 0; i--) {
            while (match >= 0 && s[match + 1] != s[i]) {
                match = prefix[match];
            }
            if (s[match + 1] == s[i]) {
                match = match + 1;
            }
        }

        string res = (match == len - 1) ? "" : s.substr(match + 1, len);
        reverse(res.begin(), res.end());
        return (res + s);
    }
};

int main()
{
    string s;
    Solution obj;

    // case 1
    s = "aacecaaa";
    cout << "string is " << s << endl;
    cout << obj.shortestPalindrome2(s) << endl;

    // case 2
    s = "abcd";
    cout << "string is " << s << endl;
    cout << obj.shortestPalindrome2(s) << endl;

    return 0;
}
