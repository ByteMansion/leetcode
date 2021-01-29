
/**
 * @brief Leetcode 875 Koko Eating Bananas
 * 
 * Koko loves to eat bananas.  There are N piles of bananas, the i-th pile has piles[i] bananas.
 * The guards have gone and will come back in H hours.
 * Koko can decide her bananas-per-hour eating speed of K.  Each hour, she chooses some pile of
 * bananas, and eats K bananas from that pile.  If the pile has less than K bananas, she eats all
 * of them instead, and won't eat any more bananas during this hour.
 * Koko likes to eat slowly, but still wants to finish eating all the bananas before the guards come back.
 * 
 * Return the minimum integer K such that she can eat all the bananas within H hours.
 */

#include "../include/utils.hpp"

using namespace std;

class Solution {    
public:
    void get_speed_limit(const vector<int>& piles, int H,
                         int& min_speed, int& max_speed) {
        long int sum = 0;
        for(auto pile: piles) {
            if(pile > max_speed) {
                max_speed = pile;
            }
            sum += pile;
        }
        min_speed = (sum - 1) / H + 1;

    }
    int get_spent_time(const vector<int>& piles, const int speed) {
        int time = 0;
        for(auto pile: piles) {
            int time_per_pile = (pile - 1) / speed + 1;
            time += time_per_pile;
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int H) {
        int min_speed = INT_MAX;
        int max_speed = INT_MIN;
        get_speed_limit(piles, H, min_speed, max_speed);
        while(min_speed < max_speed) {
            int speed = min_speed + (max_speed - min_speed) / 2;
            int time = get_spent_time(piles, speed);
            if(time > H) {
                min_speed = speed + 1;
            } else {
                max_speed = speed;
            }

        }
        return min_speed;
    }
};

int main()
{
    Solution obj;
    int H;
    vector<int> piles;

    // case 1
    piles = {3, 6, 7, 11};
    H = 8;
    cout << obj.minEatingSpeed(piles, H) << endl;

    // case 2
    piles = {30, 11, 23, 4, 20};
    H = 5;
    cout << obj.minEatingSpeed(piles, H) << endl;

    // case 3
    piles = {30, 11, 23, 4, 20};
    H = 6; 
    cout << obj.minEatingSpeed(piles, H) << endl;
    
    // case 4
    piles = {312884470};
    H = 312884469;
    cout << obj.minEatingSpeed(piles, H) << endl;

    return 0;
}