/**
 * @file leetcode95.cpp
 * 
 * @brief Leetcode 95 Unique Binary Search Trees II
 * 
 * Given an integer n, return all the structurally unique BST's (binary
 * search trees), which has exactly n nodes of unique values from 1 to n.
 * Return the answer in any order.
 * 
 */
#include "../include/utils.hpp"

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTreesHelper(int start, int end) {
        if(start > end) {
            return {nullptr};  // Cannot return empty vector, but a vector with null pointer
        }
        vector<TreeNode*> results;
        for(int i = start; i <= end; i++) {
            
            vector<TreeNode*> leftTrees = generateTreesHelper(start, i-1);
            vector<TreeNode*> rightTrees = generateTreesHelper(i+1, end);
            
            for(auto& left: leftTrees) {
                for(auto& right: rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    results.push_back(root);
                }
            }
        }
        return results;
    }
    vector<TreeNode*> generateTrees(int n) {
        // generate tree from start to end
        return generateTreesHelper(1, n); 
    }
};

int main()
{
    Solution obj;
    int n;
    vector<TreeNode*> results;

    // case 1
    n = 3;
    results = obj.generateTrees(n);
    for(auto node: results) {
        print_tree(node);
    }


    return 0;
}