/**
 * @brief Leetcode 28 Find the Index of the First Occurrence in a String
 * Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, 
 * or -1 if needle is not part of haystack.

 */
#include "utils.hpp"

class Solution {
public:
    /**
     * Solution 1: string processing
     * 
     * time complexity: O(mn)
     * space complexity: O(m) for sub string
     */
    int strStr(string haystack, string needle) {
        int len1 = haystack.length();
        int len2 = needle.length();
        if (len1 < len2) {
            return -1;
        }
        for (int i = 0; i <= len1 - len2; i++) {
            string str = haystack.substr(i, len2);
            if (str == needle) {
                return i;
            }
        }
        return -1;
    }
    /**
     * Solution 2: KMP algorithm
     * 
     * time complexity: O(n)
     * space complexity: O(m)
     */
    int strStr2(string haystack, string needle) {
        int len1 = haystack.length();
        int len2 = needle.length();
        if (len1 < len2) {
            return -1;
        }
        vector<int> pi(len2, -1);
        preprocess(pi, needle);
        int match = -1;
        for (int i = 0; i < len1; i++) {
            while (match >= 0 && needle[match + 1] != haystack[i]) {
                match = pi[match];
            }
            if (needle[match + 1] == haystack[i]) {
                match += 1;
            }
            if (match == len2 - 1) {
                return (i + 1 - len2);
            }
        }
        return -1;

    }
private:
    /* KMP compute prefix function */
    void preprocess(vector<int> &pi, string s) {
        int len = s.length();
        int k = -1;
        for (int i = 1; i < len; i++) {
            while (k >= 0 && s[k + 1] != s[i]) {
                k = pi[k];
            }
            if (s[k + 1] == s[i]) {
                k += 1;
            }
            pi[i] = k;
        }
    }
};

int main() {
    Solution obj;
    string haystack, needle;

    // case 1
    haystack = "sadbutsad";
    needle = "sad";
    std::cout << "haystack: " << haystack << " needle: " << needle << std::endl;
    std::cout << "result: " << obj.strStr(haystack, needle) << std::endl;
    std::cout << "result: " << obj.strStr2(haystack, needle) << std::endl;

    // case2
    haystack = "butsad";
    needle = "sad";
    std::cout << "haystack: " << haystack << " needle: " << needle << std::endl;
    std::cout << "result: " << obj.strStr(haystack, needle) << std::endl;
    std::cout << "result: " << obj.strStr2(haystack, needle) << std::endl;

    // case 3
    haystack = "leetcode";
    needle = "leec";
    std::cout << "haystack: " << haystack << " needle: " << needle << std::endl;
    std::cout << "result: " << obj.strStr(haystack, needle) << std::endl;
    std::cout << "result: " << obj.strStr2(haystack, needle) << std::endl;
}
