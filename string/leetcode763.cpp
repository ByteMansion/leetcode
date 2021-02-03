/**
 * @file leetcode763.cpp
 * @brief Leetcode 763 Partition Labels
 * 
 * A string S of lowercase English letters is given. We want to
 * partition this string into as many parts as possible so that each 
 * letter appears in at most one part, and return a list of integers 
 * representing the size of these parts.
 * 
 */
#include "../include/utils.hpp"

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        map<char, int> mChToIdx;
        for(int i = 0; i < S.length(); i++) {
            mChToIdx[S[i]] = i;
        }
        vector<int> results;
        int start = 0;
        int end = 0;
        for(int i = 0; i < S.length(); i++) {
            end = max(mChToIdx[S[i]], end);
            if(i == end) {
                results.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return results;
    }
};

int main()
{
    Solution obj;
    string S;
    vector<int> results;

    // case 1
    S = "ababcbacadefegdehijhklij";
    results = obj.partitionLabels(S);
    print_array(results);

    return 0;
}