/**
 * @brief   Leetcode 633 Sum of Square Numbers
 * 
 */

#include "utils.hpp"
#include <cmath>

class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        if (c == 0)
        {
            return true;
        }
        long long int l = 0;
        long long int r = sqrt(c);  // (c - 1) / 2 + 1;
        while (l <= r)
        {
            long long int n = l * l + r * r;
            if (n > c)
            {
                r--;
            }
            else if (n < c)
            {
                l++;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution obj;
    int c;

    // case 1
    c = 100000;
    cout << c << endl;
    cout << "Results:" << obj.judgeSquareSum(c) << endl;

    // case 2
    c = 2147483646;
    cout << c << endl;
    cout << "Results:" << obj.judgeSquareSum(c) << endl;

    return 0;
}