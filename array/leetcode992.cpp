/**
 * @brief   Leetcode 992 Subarrays with K Different Integers
 *
 * Given an array A of positive integers, call a (contiguous, 
 * not necessarily distinct) subarray of A good if the number 
 * of different integers in that subarray is exactly K.
 *
 * (For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)
 */
#include "../include/utils.hpp"
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
public:
    /**
     * 1st solution: brute force
     *
     * time complexity: O(n^3)
     * space complexity: O(n)
     */
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int result = 0;
        unordered_map<int, int> mEleToCnt;
        for(int i = 0; i < A.size() - K + 1; i++) {
            for(int j = i + K; j < A.size() + 1; j++) {
                mEleToCnt.clear();
                int cnt = 0;
                for(int m = i; m < j; m++) {
                    if(mEleToCnt[A[m]] == 0) {
                        mEleToCnt[A[m]]++;
                        cnt++;
                    }
                }
                if(cnt == K) {
                    result++;
                }
            }
        }
        return result;
    }

};

int main()
{
    vector<int> A;
    int K;
    Solution obj;

    // case 1
    A = {1, 1, 2, 2, 2, 1, 2, 2, 3};
    K = 2;
    print_array(A);
    cout << K << endl;
    cout << obj.subarraysWithKDistinct(A, K) << endl;

    //case 2
    A = {1, 2, 1, 3, 4};
    K = 3;
    print_array(A);
    cout << K << endl;
    cout << obj.subarraysWithKDistinct(A, K) << endl;

    // case 3
    A = {1, 2, 3, 3, 3, 3, 4};
    K = 5;
    print_array(A);
    cout << K << endl;
    cout << obj.subarraysWithKDistinct(A, K) << endl;

    return 0;
}
