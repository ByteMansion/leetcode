/**
 * @brief   Leetcode 409: Longest Palindrom
 *  Given a string which consists of lowercase or uppercase letters, find the
 *  length of the longest palindromes that can be built with those letters.
 *
 *  This is case sensitive, for example "Aa" is not considered a palindrome here.
 *
 *  NOTE:
 *   Assume the length of given string will not exceed 1,010.
 */
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        if(s.length() == 0 || s.length() == 1) {
            return s.length();
        }
        // construct a mapping from letter to count
        vector<int> cTable(52, 0);
        for(int idx = 0; idx < s.length(); idx++) {
            cTable[s[idx] - 'A'] += 1;
        }

        int maxOdd = INT_MIN;
        int sumEven = 0;
        for(int idx = 0; idx < 52; idx++) {
            int count = cTable[idx];
            if(count % 2) {
                maxOdd = max(maxOdd, count);
            } else {
                sumEven += count;
            }
        }

        return (sumEven + maxOdd);
    }
};

int main()
{
    string s;
    Solution obj;

    // case 1
    s = "Aa";
    cout << s << ":" << obj.longestPalindrome(s) << endl;

    // case2
    s = "abccccdd";
    cout << s << ":" << obj.longestPalindrome(s) << endl;

    // case3
    s = "AAssaaadddwdddddd";
    cout << s << ":" << obj.longestPalindrome(s) << endl;

    return 0;
}
