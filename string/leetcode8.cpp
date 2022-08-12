/**
 * @brief   Leetcode 8 Atoi
 * 
 */
#include "utils.hpp"
#include <vector>
#include <string>
extern "C" {
#include <stdint.h>
}

class Solution {
public:
    int myAtoi(string s) {
        vector<vector<int>> transfer = 
            { { 0,  1,  2, -1},
              { 3, -1,  2, -1},
              { 3, -1,  2, -1},
              { 3, -1, -1, -1},
            };
        int state = 0;
        int64_t value = 0;
        int negative = 1;
        for(int i = 0; i < s.length(); i++) {
            char ch = s.at(i);
            int id = make(ch);
            state = transfer[state][id];
            if(state < 0) {
                break;
            } else if(state == 1) {
                if(ch == '-') {
                    negative = -1;
                }
            } else if(state == 2) {
                value = value * 10 + ch - '0';
            }

            if((negative == -1) && (value > ((int64_t)1 << 31))) {
                return INT32_MIN;
            } else if((negative == 1) && value > INT32_MAX) {
                return INT32_MAX;
            }
        }
        return (negative * value);
    }

private:
    int make(const char ch) {
        switch(ch) {
            case ' ': return 0;
            case '-':
            case '+': return 1;
        }
        return is_digit(ch);
    }
    int is_digit(const char ch) {
        if(ch >= '0' && ch <= '9') {
            return 2;
        }
        return 3;
    }
};

int main()
{
    Solution obj;
    string s;

    // case 1
    s = "  -112 asdf";
    cout << s << ": " << obj.myAtoi(s) << endl;

    // case 2
    s = " +dfs";
    cout << s << ": " << obj.myAtoi(s) << endl;

    // case 3
    s = "-13.4";
    cout << s << ": " << obj.myAtoi(s) << endl;

    // case 4
    s = "words and 987";
    cout << s << ": " << obj.myAtoi(s) << endl;

    // case 5
    s = "-91283472332";
    cout << s << ": " << obj.myAtoi(s) << endl;

    // case 6
    s = "   91283472332";
    cout << s << ": " << obj.myAtoi(s) << endl;
    
    return 0;
}