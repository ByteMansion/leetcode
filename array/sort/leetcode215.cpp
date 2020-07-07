/**
 * @brief   Leetcode 215 Kth Largest Element in An Array
 *
 *  Find the kth largest element in an unsorted array. Note that
 *  it is the kth largest element in the sorted order, not the Kth
 *  distinct element.
 *
 */

#include "../../include/utils.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

class Solution {
public:
    /**
     * 1st solution: use STL algorithm
     *
     * time complexity depends on STL sort algorithm, O(nlogn)
     *
     */
    int findKthLargest(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end(), greater<int>());
        return nums[k - 1];
    }

public:
    /**
     * 2nd solution: use quicksort algorithm
     *
     */
    int findKthLargest2(vector<int>& nums, int k) {
        srand(time(0));
        // sort in ascending order
        // select kth largest element ranging from left index to right index
        return quickSelect(nums,
                           0 /*left index*/,
                           nums.size()-1 /*right index*/,
                           nums.size()-k /*position of the kth largest*/);
    }
private:
    int quickSelect(vector<int>& nums, int l, int r, int pos)
    {
        int pivot = randomPartition(nums, l, r);
        if(pivot == pos) {
            return nums[pos];
        }

        return (pivot > pos) ?
               quickSelect(nums, l, pivot-1, pos) :
               quickSelect(nums, pivot+1, r, pos);
    }

    inline int randomPartition(vector<int>& nums, int l, int r)
    {
        int p = rand() % (r - l + 1) + l;
        swap(nums[p], nums[r]);  // exchange p-th element with right index
        return paritition(nums, l, r);
    }

    inline int paritition(vector<int>& nums, int l, int r)
    {
        int i = l - 1;
        for(int idx = l; idx < r; idx++) {
            if(nums[idx] <= nums[r]) {
                swap(nums[++i], nums[idx]);
            }
        }
        swap(nums[i+1], nums[r]);

        return i+1;
    }

public:
    /**
     * 3nd solution: using heap sort
     *
     * Special data structure, such as heap or priority can solve this
     * issue, but heap sort is preferred for interviewee.
     */
    int findKthLargest3(vector<int>& nums, int k)
    {
        int heapsize = nums.size();
        buildMaxHeap(nums, heapsize);

        // loop (k-1) times
        for(int i = nums.size()-1; i >= nums.size()-k+1; --i) {
            swap(nums[0], nums[i]);
            heapsize--;
            maxHeapify(nums, 0, heapsize);
        }

        return nums[0];
    }

private:
    void buildMaxHeap(vector<int>& nums, int heapsize)
    {
        for(int i = heapsize / 2; i >= 0; --i) {
            maxHeapify(nums, i, heapsize);
        }
    }

    void maxHeapify(vector<int>& nums,
                    int i,
                    int heapsize)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int largest = i;

        if(l < heapsize && nums[l] > nums[largest]) {
            largest = l;
        }
        if(r < heapsize && nums[r] > nums[largest]) {
            largest = r;
        }
        if(largest != i) {
            swap(nums[i], nums[largest]);
            i++;
            maxHeapify(nums, i, heapsize);
        }
    }
};


int main()
{
	vector<int> nums;
	Solution obj;
    int k;

    // case 1
    nums = {3, 2, 1, 5, 6, 4};
    k = 2;
    print_array(nums);
    cout << k << endl;
    cout << obj.findKthLargest3(nums, k) << endl;

    // case 2
    nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    k = 4;
    print_array(nums);
    cout << k << endl;
    cout << obj.findKthLargest3(nums, k) << endl;

	return 0;
}


