/**
 * @brief Leetcode 756 Pyramid Transition Matrix
 * 
 */
#include "utils.hpp"
#include <string>
#include <unordered_map>

class Solution {
public:
    /**
     * solution 1: brute force
     * result: exceed time limit
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
        if(levels.empty() || levels[0].length() != bottom.length()-1) {
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

public:
    /**
     * solution: backtrace
     * 
     * @param bottom 
     * @param allowed 
     * @return true 
     * @return false 
     */
    bool pyramidTransition2(string bottom, vector<string> &allowed){
        // preprocess dictionary allowed
        for(auto str: allowed) {
            str2char[str.substr(0,2)].push_back(str[2]);
        }
        int n = bottom.length();
        vector<string> tower(n);
        tower[n-1] = bottom;
        return dfs(tower, n-1, 0);
    }
private:
    unordered_map<string, vector<char>> str2char;
    bool dfs(vector<string> &tower, int r, int c) {
        if(r == c) {
            c = 0;
            --r;
        }
        if(r == 0) {
            return true;
        }
        string prefix = tower[r].substr(c, 2);
        if(str2char.find(prefix) == str2char.end()) {
            return false;
        }

        for(auto ch: str2char[prefix]) {
            tower[r-1].push_back(ch);
            if(dfs(tower, r, c+1)) {
                return true;
            }
            tower[r-1].pop_back();
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
        while ((std::cin >> tmp))
        {
            allowed.push_back(tmp);
        }

        cout << obj.pyramidTransition2(bottom, allowed) << endl;

        return 0;
}

