/**
 * @brief   Leetcode 992 Subarrays with K Different Integers
 *
 * Given an array A of positive integers, call a (contiguous, 
 * not necessarily distinct) subarray of A good if the number 
 * of different integers in that subarray is exactly K.
 *
 * (For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)
 */
#include "utils.hpp"
#include <unordered_map>
#include <map>

using namespace std;

class Window {
public:
    unordered_map<int, int> mEleToCnt;
    int distCnt;
    Window() {
        distCnt = 0;
    }

    void add(int val) {
        mEleToCnt[val]++;
        if(mEleToCnt[val] == 1) {
            distCnt++;
        }
    }
    void remove(int val) {
        mEleToCnt[val]--;
        if(mEleToCnt[val] == 0) {
            distCnt--;
        }
    }

};

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

    /**
     * 2nd solution: sliding window
     *
     * time complexity: O(n)
     * space complexity: O(n)
     */
    int subarraysWithKDistinct2(vector<int>& A, int K) {
        return numberofNotMoreThanK(A, K) - numberofNotMoreThanK(A, K-1);
    }
private:
    int numberofNotMoreThanK(vector<int>& A, int K) {
        int size = A.size();
        vector<int> eleCnt(size+1, 0);
        int result = 0;
        int numofDist = 0;
        int low = 0;
        int high = -1;
        while(high != size - 1) {
            eleCnt[A[++high]]++;
            if(eleCnt[A[high]] == 1) {
                numofDist++;
            }
            while(numofDist > K) {
                eleCnt[A[low]]--;
                if(eleCnt[A[low]] == 0) {
                    numofDist--;
                }
                low++;
            }
            result += high - low;
        }
        return result;
    }

public:
    /**
     * 3rd solution: sliding window
     * This is the offlical solution.
     *
     * time complexity: O(n)
     * space complexity: O(n)
     */
    int subarraysWithKDistinct3(vector<int>& A, int K) {
        Window window1;
        Window window2;
        int left1 = 0;
        int left2 = 0;
        int ans = 0;
        for(int rIdx = 0; rIdx < A.size(); rIdx++) {
            int val = A[rIdx];
            window1.add(val);
            window2.add(val);
            while(window1.distCnt > K) {
                window1.remove(A[left1++]);
            }
            while(window2.distCnt >= K) {
                window2.remove(A[left2++]);
            }
            ans += left2 - left1;
        }
        return ans;
    }

};

int main()
{
    vector<int> A;
    int K;
    Solution obj;

    // case 1
    A = {1, 2, 1, 1, 2, 2, 2, 3};
    K = 2;
    print_array(A);
    cout << K << endl;
    cout << obj.subarraysWithKDistinct2(A, K) << endl;

    //case 2
    A = {1, 2, 1, 3, 4};
    K = 3;
    print_array(A);
    cout << K << endl;
    cout << obj.subarraysWithKDistinct2(A, K) << endl;

    // case 3
    A = {1, 2, 3, 3, 3, 3, 4};
    K = 5;
    print_array(A);
    cout << K << endl;
    cout << obj.subarraysWithKDistinct2(A, K) << endl;

    return 0;
}
