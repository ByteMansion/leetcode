/**
 * @brief   Leetcode 718 Maximum Length of Repeated Subarray
 * Given two integer arrays A and B, return the maximum length 
 * of an subarray that appears in both arrays.
 *
 * Note:
 * 1 <= len(A),len(B) <= 1000
 * 0 <= A[i],B[i] < 100
 */

#include "utils.hpp"
#include <map>

using namespace std;

class Solution {
public:
    /**
     * 1st solution: brute force
     *
     * time complexity: O(n^2)
     * space complexity: (O(N)
     */
    int findLength(vector<int>& A, vector<int>& B) {
        int result = 0;
        map<int, vector<int>> eleToIdx;
        for(int i = 0; i < B.size(); i++) {
            eleToIdx[B[i]].push_back(i);
        }
        for(int i = 0; i < A.size(); i++) {
            if(eleToIdx.find(A[i]) == eleToIdx.end()) {
                continue;
            }
            vector<int> idxVec = eleToIdx[A[i]];
            for(int j = 0; j < idxVec.size(); j++) {
                int aIdx = i;
                int bIdx = idxVec[j];
                while(A[aIdx] == B[bIdx]) {
                    aIdx++; bIdx++;
                    if(aIdx >= A.size() || bIdx >= B.size()) {
                        break;
                    }
                }
                result = max(result, aIdx - i);
            }
        }
        return result;
    }

    /**
     * 2nd solution: dynamic programming
     *
     */
    int findLength2(vector<int>& A, vector<int>& B) {
        int aLen = A.size();
        int bLen = B.size();
        int maxLen = 0;
        vector<vector<int>> dp(aLen+1, vector<int>(bLen+1, 0));
        for(int i = aLen - 1; i >= 0; i--) {
            for(int j = bLen - 1; j >= 0; j--) {
                if(A[i] == B[j]) {
                    dp[i][j] += dp[i+1][j+1] + 1;
                    maxLen = max(maxLen, dp[i][j]);
                }
            }
        }
        return maxLen;
    }
};

int main()
{
    vector<int> A;
    vector<int> B;
    Solution obj;

    // case 1
    A = {1, 2, 3, 2, 1};
    B = {3, 2, 1, 4, 7};
    print_array(A);
    print_array(B);
    cout << obj.findLength2(A, B) << endl;

    return 0;
}
