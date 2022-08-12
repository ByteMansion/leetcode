/**
 * @brief  Leetcode 524 Longest Word in Dictionary through Deleting
 * 
 */

#include "utils.hpp"
#include <string>

class Solution
{
public:
    string findLongestWord(string s, vector<string> &dictionary)
    {
        string resStr = "";
        int maxLen = 0;
        sort(dictionary.begin(), dictionary.end(), [](auto &s1, auto &s2)
             { return s1.length() > s2.length(); });
        for (auto str : dictionary)
        {
            if (str.length() < maxLen)
            {
                break;
            }
            int cnt = 0;
            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] == str[cnt])
                {
                    cnt++;
                    if (cnt == str.length())
                    {
                        break;
                    }
                }
            }
            if (cnt == str.length() && str.length() >= maxLen)
            {
                if (str.length() == maxLen && resStr < str)
                {
                    continue;
                }
                resStr = str;
                maxLen = str.length();
            }
        }
        return resStr;
    }
};

int main()
{
    Solution obj;
    string s = "abpcplea";
    vector<string> dictionary = { "ale", "apple", "abcle", "monkey", "plea"};
    cout << obj.findLongestWord(s, dictionary) << endl;

    return 0;
}