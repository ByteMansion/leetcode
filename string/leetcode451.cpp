/**
 * @file leetcode451.cpp
 * @brief Leetcode 451 Sort Characters By Frequency
 * 
 */
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        if (s.length() <= 1)
        {
            return s;
        }

        // map character to its frequency
        map<char, int> chToCnt;
        for (auto c : s)
        {
            chToCnt[c]++;
        }
        // construct min priority queue by frequency
        auto cmp = [](auto m, auto n) { return m.second < n.second; };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);
        for (auto ele : chToCnt)
        {
            pq.push(ele);
        }
        // generate result
        string res = "";
        while (!pq.empty())
        {
            auto ele = pq.top();
            for (int j = 0; j < ele.second; j++)
            {
                res += ele.first;
            }
            pq.pop();
        }
        return res;
    }
};

int main()
{
    Solution obj;
    string s;

    // Case 1
    s = "tree";
    cout << "Result: " << obj.frequencySort(s) << endl;

    // Case 2
    s = "AaCC";
    cout << "Result: " << obj.frequencySort(s) << endl;

    // Case 3
    s = "aaaaCCCC";
    cout << "Result: " << obj.frequencySort(s) << endl;

    return 0;
}
