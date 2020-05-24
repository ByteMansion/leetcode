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
#include <map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        if(s.length() == 0 || s.length() == 1) {
            return s.length();
        }
        // construct a mapping from letter to count
        map<char, int> cTable;
        for(int idx = 0; idx < s.length(); idx++) {
            cTable[s[idx]] += 1;
        }

        int existOdd = 0;
        int sumEven = 0;
        for(char iter = 'A'; iter <= 'z'; iter++) {
            int count = cTable[iter];
            if(count % 2) {
                existOdd = 1;
                sumEven += count - 1;
            } else {
                sumEven += count;
            }
        }

        return (sumEven + existOdd);
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
