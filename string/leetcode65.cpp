/**
 * @brief   Leetcode 65 Valid Number
 * 
 */
#include "utils.hpp"
#include <iostream>
#include <string>

class Solution {
public:
    /**
     * DFA, Deterministic Finite Automation
     * 
     * @param s 
     * @return true 
     * @return false 
     */
    bool isNumber(string s) {
        if(s.empty()) {
            return false;
        }
        vector<bool> finals = {false, false, false,true, false, true, true, false, true};
        vector<vector<int>> transfer = 
            // ' ' +/-  . 0-9  e/E 
            { { 0,  1,  2,  6,  -1, -1},  // state 0
              {-1, -1,  2,  6,  -1, -1},  // state 1
              {-1, -1, -1,  3,  -1, -1},  // state 2
              {8,  -1, -1,  3,   4, -1},  // state 3
              {-1,  7, -1,  5,  -1, -1},  // state 4
              {8,  -1, -1,  5,  -1, -1},  // state 5
              {8,  -1,  3,  6,   4, -1},  // state 6
              {-1, -1, -1,  5,  -1, -1},  // state 7
              {8,  -1, -1,  -1, -1, -1},  // state 8
            };
        int n = s.length();
        int state = 0;
        for(int i = 0; i < n; i++) {
            char ch = s.at(i);
            int id = make(ch);
            state = transfer[state][id];
            if(state < 0) {
                return false;
            }
        }
        return finals[state];
    }
private:
    int make(const char ch) {
        switch(ch) {
            case ' ': return 0;
            case '-':
            case '+': return 1;
            case '.': return 2;
            case 'e':
            case 'E': return 4;
        }
        return is_digit(ch);
    }
    int is_digit(const char ch) {
        if(ch >= '0' && ch <= '9') {
            return 3;
        }
        return 5;
    }
};

int main()
{
    Solution obj;
    string s;

    // case 1: true
    s = "-0.1";
    cout << s << ": " << obj.isNumber(s) << endl;

    // case 2: true
    s = ".134  ";
    cout << s << ": " << obj.isNumber(s) << endl;

    // case 3: true
    s = "    +132.e214";
    cout << s << ": " << obj.isNumber(s) << endl;

    // case 4: false
    s = "343sfa3";
    cout << s << ": " << obj.isNumber(s) << endl;

    // case 5: true
    s = "  -.4E2334";
    cout << s << ": " << obj.isNumber(s) << endl;

    // case 6: true
    s = "345E-2334";
    cout << s << ": " << obj.isNumber(s) << endl;
    
    return 0;
}