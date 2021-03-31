/**
 * @brief   Leetcode 14 Longest Common Prefix
 * 
 */
#include "../include/utils.hpp"
#include <string>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) {
            return "";
        }
        int strCnt = strs.size();
        int minLen = getMinLength(strs);
        for(int len = 1; len <= minLen; len++) {
            string substr = strs[0].substr(0, len);
            for(int idx = 1; idx < strCnt; idx++) {
                string tmp = strs[idx].substr(0, len);
                if(tmp != substr) {
                    return strs[idx].substr(0, len-1);
                }
            }
        }
        return strs[0].substr(0, minLen);        
    }
private:
    int getMinLength(const vector<string> strs) {
        int minLen = 0;
        for(auto str: strs) {
            minLen = (minLen < str.length()) ? str.length() : minLen;
        }
        return minLen;
    }
};

int main()
{
    Solution obj;
    vector<string> strs;

    // case 1
    strs = {"flower", "flour", "flow"};
    print_array(strs);
    cout << obj.longestCommonPrefix(strs) << endl;

    // case 2
    strs = {};
    print_array(strs);
    cout << obj.longestCommonPrefix(strs) << endl;

    // case 3
    strs = {""};
    print_array(strs);
    cout << obj.longestCommonPrefix(strs) << endl;

    // case 4
    strs = {"asf", "gdf", "erew"};
    print_array(strs);
    cout << obj.longestCommonPrefix(strs) << endl;

    return 0;
}