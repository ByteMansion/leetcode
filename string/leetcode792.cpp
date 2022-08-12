/**
 * @brief   Leetcode 792: Number of Matching Subsequences
 *
 * Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.
 *
 * Example :
 * Input: 
 * S = "abcde"
 * words = ["a", "bb", "acd", "ace"]
 * Output: 3
 * Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace".
 *
 * Note:
 * 1. All words in words and S will only consists of lowercase letters.
 * 2. The length of S will be in the range of [1, 50000].
 * 3. The length of words will be in the range of [1, 5000].
 * 4. The length of words[i] will be in the range of [1, 50].
 */

#include "utils.hpp"
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    /**
     * 1st solution: brute force
     */
    int numMatchingSubseq(string S, vector<string>& words) {
        int result = 0;

        for(size_t i = 0; i < words.size(); i++) {
            if(isSubsequence(words[i], S)) {
                result++;
            }
        }

        return result;
    }

    /**
     * 2nd solution: create lookup table
     *
     */
    int numMatchingSubseq2(string S, vector<string>& words) {
        // create lookup table
        vector<vector<int>> tbl(26, vector<int>{});
        for(size_t sIdx = 0; sIdx < S.length(); sIdx++) {
            tbl[S[sIdx]-'a'].push_back(sIdx);
        }
        int count = 0;
        for(size_t idx = 0; idx < words.size(); idx++) {
            if(isMatching(tbl, words[idx])) {
                count++;
            }
        }
        return count;
    }

private:
    bool isSubsequence(string s, string t) {
        size_t sIdx = 0;

        for(size_t tIdx = 0; tIdx < t.length(); tIdx++) {
            if(s[sIdx] == t[tIdx]) {
                sIdx++;
            }
            if(sIdx == s.length()) {
                return true;
            }
        }
        if(sIdx == s.length()) {
            return true;
        }

        return false;
    }

    int find_smallest_pos(vector<int>& list, int pos) {
        int left = 0;
        int right = list.size()-1;
        while(left + 1 < right) {
            int mid = left + (right - left) / 2;
            if(list[mid] > pos) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if(list[left] > pos) return list[left];
        if(list[right] > pos) return list[right];
        return -1;
    }

    bool isMatching(vector<vector<int>>& tbl, string cmp) {
        int pre = -1;
        for(size_t idx = 0; idx < cmp.length(); idx++) {
            if(tbl[cmp[idx]-'a'].empty()) {
                return false;
            }
            int pos = find_smallest_pos(tbl[cmp[idx]-'a'], pre);
            if(pos == -1) {
                return false;
            }
            pre = pos;
        }
        return true;
    }
};

int main()
{
    Solution obj;
    string S;
    vector<string> words;

    // case 1
    S = "abcde";
    words = {"a", "bb", "acd", "ace"};
    cout << obj.numMatchingSubseq2(S, words) << endl;

    // case 2
    S = "adfadfrfdgsdgdfghdfdjhdfdtfbfgdrwesdhgjsjkukisqqq";
    words = {"saefs", "thfger", "wdsfaw", "dffd"};
    cout << obj.numMatchingSubseq2(S, words) << endl;

    // case 3
    S = "dsahjpjauf";
    words = {"ahjpjau", "ja", "ahbwzgqnuk", "tnmlanowax"};
    cout << obj.numMatchingSubseq2(S, words) << endl;

    return 0;
}
