/**
 * @brief   Leetcode 04.08 First Common Ancestor LCCI
 * Design an algorithm and write code to find the first common
 * ancestor of two nodes in a binary tree. Avoid storing additional
 * nodes in a data structure.
 *
 * NOTE: This is not necessarily a binary search tree.
 */

#include "../include/utils.hpp"
#include <iostream>

using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left == NULL) {
            return right;
        }
        if(right == NULL) {
            return left;
        }
        return root;
    }
};

int main(int argc, char** argv)
{
    TreeNode* root = new TreeNode(3);
    TreeNode* node1 = new TreeNode(5);
    TreeNode* node2 = new TreeNode(1);
    TreeNode* node3 = new TreeNode(6);
    TreeNode* node4 = new TreeNode(2);
    TreeNode* node5 = new TreeNode(0);
    TreeNode* node6 = new TreeNode(8);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node8 = new TreeNode(4);

    root->left = node1; root->right = node2;
    node1->left = node3; node1->right = node4;
    node2->left = node5; node2->right = node6;
    node4->left = node7; node4->right = node8;

    Solution obj;
    TreeNode* p;
    TreeNode* q;
    TreeNode* result;

    // case 1
    p = node3; q = node5;
    result = obj.lowestCommonAncestor(root, p, q);
    cout << "p = " << p->val << ", q = " << q->val
         << ", Ancestor = " << result->val << endl;

    // case 2
    p = node1; q = node4;
    result = obj.lowestCommonAncestor(root, p, q);
    cout << "p = " << p->val << ", q = " << q->val
         << ", Ancestor = " << result->val << endl;


    delete root; delete node1; delete node2;
    delete node3; delete node4; delete node5;
    delete node6; delete node7; delete node8;

    return 0;
}
