/**
 * @brief   Leetcode 605 Can Place Flowers
 * You have a long flowerbed in which some of the plots are planted, 
 * and some are not. However, flowers cannot be planted in adjacent plots.
 * 
 * Given an integer array flowerbed containing 0's and 1's, 
 * where 0 means empty and 1 means not empty, and an integer n, 
 * return if n new flowers can be planted in the flowerbed without 
 * violating the no-adjacent-flowers rule.
 * 
 */
#include "../include/utils.hpp"

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        int cnt = 0;
        // corner case: capacity is 1
        if(size == 1) {
            if(flowerbed[0] == 0) {
                cnt++;
            }
            return n <= cnt;
        }

        // head
        if(flowerbed[0] == 0 && flowerbed[1] == 0) {
            flowerbed[0] = 1;
            cnt++;
        }
        // internal
        // if count is n, we can return head
        for(int i = 1; i < size - 1; i++) {
            if(flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0) {
                cnt++;
                flowerbed[i] = 1;
            }
        }
        // tail
        if(flowerbed[size-2] == 0 && flowerbed[size-1] == 0) {
            cnt++;
            flowerbed[size-1] = 1;
        }
        return n <= cnt;
    }
};

int main()
{
    Solution obj;
    vector<int> flowerbed;
    int n;

    // case 1
    flowerbed = {1, 0, 0, 0, 1};
    n = 1;
    cout << obj.canPlaceFlowers(flowerbed, n) << endl;

    // case 2
    n = 2;
    cout << obj.canPlaceFlowers(flowerbed, n) << endl;

    // case 3
    flowerbed = {0};
    n = 1;
    cout << obj.canPlaceFlowers(flowerbed, n) << endl;


    return 0;
}