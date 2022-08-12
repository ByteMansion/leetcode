/**
 * @brief  Leetcode 680 Valid Palindrome II
 * 
 */

#include "utils.hpp"
#include <cstring>

class Solution
{
public:
    bool validPalindrome(string s)
    {
        int delCnt = 0;
        return validPalindromeHelper(s, delCnt);
    }
    private:
    bool validPalindromeHelper(string s, int& delCnt)
    {
        int len = s.length();
        if (len == 1)
        {
            return true;
        }
        bool res1 = false;
        bool res2 = false;
        int i = 0;
        for (; i < len / 2 + 1; i++)
        {
            if (s[i] == s[len - i - 1])
            {
                continue;
            }
            if (++delCnt > 1)
            {
                return false;
            }
            break;
        }
        if (i == len / 2 + 1)
        {
            return true;
        }
        res1 = validPalindromeHelper(s.substr(i + 1, len - 2 * i - 1), delCnt);
        res2 = validPalindromeHelper(s.substr(i, len - 2 * i - 1), delCnt);
        return (res1 || res2);
    }
};

int main()
{
    Solution obj;
    string s;

    // case 1: expected result is false
    s = "abcde";
    cout << s << ": " << obj.validPalindrome(s) << endl;

    // case 2: expected result is true
    s = "aba";
    cout << s << ": " << obj.validPalindrome(s) << endl;

    // case 3: expected result is true
    s = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
    cout << s << ": " << obj.validPalindrome(s) << endl;

    return 0;
}