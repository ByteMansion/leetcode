/**
 * @file mianshi17.cpp
 * @brief 面试题 17
 * 
 * Design an algorithm to find the smallest K numbers in an array.
 * 
 * Example:
 * Input:  arr = [1,3,5,7,2,4,6,8], k = 4
 * Output:  [1,2,3,4]
 * 
 * Note:
 * 
 * 0 <= len(arr) <= 100000
 * 0 <= k <= min(100000, len(arr))
 */


#include "../../include/utils.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        if(arr.empty()) {
            return vector<int>{};
        }
        return quickFind(arr, k);
    }
private:
    vector<int> quickFind(vector<int>& arr, int k) {
        // srand(time(0));
        quickSort(arr, 0, arr.size() - 1);
        print_array(arr);
        vector<int> result;
        for(int i = 0; i < k; i++) {
            result.push_back(arr[i]);
        }
        return result;
    }
    void quickSort(vector<int>& arr, int lIdx, int rIdx) {
        if(lIdx >= rIdx) {
            return;
        }
        int pivot = rand() % (rIdx - lIdx + 1) + lIdx;
        swap(arr[pivot], arr[rIdx]);
        int pos = partition(arr, lIdx, rIdx);

        quickSort(arr, lIdx, pos-1);  // cannot be pivot-1
        quickSort(arr, pos+1, rIdx);  // cannot be pivot+1
    }
    inline int partition(vector<int>& arr, int l, int r) {
        int pos = l;
        for(int i = l; i < r; i++) {
            if(arr[i] <= arr[r]) {
                swap(arr[pos], arr[i]);
                pos++;
            }
        }
        swap(arr[pos], arr[r]);
        return pos;
    }
};

int main()
{
    vector<int> arr;
    Solution obj;
    vector<int> results;
    int k;

    // case 1
    arr = {1,3,5,7,2,4,6,8};
    print_array(arr);
    k = 4;
    results = obj.smallestK(arr, k);
    print_array(results);

    return 0;
}