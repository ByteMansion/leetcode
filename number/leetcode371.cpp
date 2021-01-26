/**
 * @file leetcode371.cpp
 * @brief Leetcode 371 Sum of Two Integers
 *  Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
 * 
 */
#include <iostream>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        while(b) {
            int no_carry = (a ^ b);
            b = (unsigned int)(a & b) << 1;
            a = no_carry;
        }
        return a;
    }
};
int main()
{
    int a, b;
    Solution obj;

    // case 1
    a = 10; b = 14;
    cout << a << "+" << b << "=" << obj.getSum(a, b) << endl;

    // case 2
    a = -5; b = 3;
    cout << a << "+" << b << "=" << obj.getSum(a, b) << endl;
    

    return  0;
}