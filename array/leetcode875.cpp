
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
        cout << "min_speed=" << min_speed << " max_speed=" << max_speed << endl;
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