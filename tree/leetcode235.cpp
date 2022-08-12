/**
 * @file leetcode235.cpp
 * @brief 
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of 
 * two given nodes in the BST.
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor 
 * is defined between two nodes p and q as the lowest node in T that has both p 
 * and q as descendants (where we allow a node to be a descendant of itself).”
 * 
 */
#include "utils.hpp"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int H = max(p->val, q->val);
        int L = min(p->val, q->val);
        if(root->val <= H && root->val >= L) {
            return root;
        }
        if(H < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        return lowestCommonAncestor(root->right, p, q);
    }
};

int main() {
    Solution obj;
    TreeNode* result;

    TreeNode* root = new TreeNode(6);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node8 = new TreeNode(8);
    TreeNode* node0 = new TreeNode(0);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node9 = new TreeNode(9);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node5 = new TreeNode(5);
    root->left = node2; root->right = node8;
    node2->left = node0; node2->right = node4;
    node8->left = node7; node8->right = node9;
    node4->left = node3; node4->right = node5;

    // case 1
    result = obj.lowestCommonAncestor(root, node2, node8);
    cout << "p=" << node2->val << " q=" << node8->val << " result=" << result->val << endl;

    // case 2
    result = obj.lowestCommonAncestor(root, node0, node5);
    cout << "p=" << node0->val << " q=" << node5->val << " result=" << result->val << endl;

    return 0;
}