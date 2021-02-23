/**
 * @file leetcode406.cpp
 * @brief Leetcode 406 Queue Reconstruction by Height
 * 
 */
#include "../include/utils.hpp"
#include <map>

using namespace std;

class Solution {
public:
    /**
     * solution 1: sort with multiple keys
     *  Height in ascending order
     *  Taller people count in descending order
     * 
     */
    vector<vector<int> > reconstructQueue(vector<vector<int> >& people) {     
        sort(people.begin(), people.end(),
             [](auto& p1, auto& p2) { return p1[0] < p2[0] || (p1[0] == p2[0] && p1[1] > p2[1]);} );

        int n = people.size();
        vector<vector<int>> results(n);
        for(auto& individual: people) {
            int idx = individual[1] + 1;
            for(int i = 0; i < n; i++) {
                if(results[i].empty()) {
                    --idx;
                    if(!idx) {
                        results[i] = individual;
                        break;
                    }
                }
            }
        }
        return results;
    }

    /**
     * solution 2: sort with multiple keys
     *  Height in descending order
     *  Taller people count in asceding order
     * 
     */
    vector<vector<int>> reconstructQueue2(vector<vector<int> >& people) { 
        sort(people.begin(), people.end(),
             [](auto u, auto v) { return u[0] > v[0] || (u[0] == v[0] && u[1] < v[1]); } );

        int n = people.size();
        vector<vector<int>> results;
        for(auto individual: people) {
            results.insert(results.begin() + individual[1], individual);
        }
        return results;
    }
};


int main()
{
    vector<vector<int>> people;
    Solution obj;
    vector<vector<int>> results;

    // case 1
    people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    results = obj.reconstructQueue2(people);
    print_2d_array(results);


    return 0;
}