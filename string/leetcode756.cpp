/**
 * @brief Leetcode 756 Pyramid Transition Matrix
 * 
 */
#include "utils.hpp"
#include <string>

class Solution {
public:
    /**
     * solution 1: exceed time limit
     * 
     * @param bottom 
     * @param allowed 
     * @return true 
     * @return false 
     */
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        if(bottom.length() == 1) {
            return true;
        }
        if(allowed.size() == 0) {
            return false;
        }
        vector<string> levels;
        for(int i = 0; i < bottom.length() - 1; i++) {
            string prefix = bottom.substr(i, 2);
            vector<string> tmp;
            for(auto str: allowed) {
                if(str.substr(0, 2) != prefix) {
                    continue;
                }
                if(i == 0) {
                    tmp.push_back(str.substr(2, 1));
                    continue;
                }
                for(auto level: levels) {
                    level += str.substr(2, 1);
                    tmp.push_back(level);
                }
            }
            levels = tmp;
        }
        if(levels.empty() || levels[0].length() < bottom.length()-1) {
            return false;
        }
        for(int i = 0; i < levels.size(); i++) {
            bool res = pyramidTransition(levels[i], allowed);
            if(res == true) {
                return res;
            }
        }
        return false;
    }
};

int main()
{
    Solution obj;
    string bottom;
    vector<string> allowed;

    std::cout << "Input bottom string: ";
    std::cin >> bottom;
    string tmp;
    while((std::cin >> tmp)) {
        allowed.push_back(tmp);
    } 

    cout << obj.pyramidTransition(bottom, allowed) << endl;

    return 0;
}

