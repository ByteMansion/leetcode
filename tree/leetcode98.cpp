/**
 * @brief   Leetcode 98: Validate Binary Search Tree
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
    - The left subtree of a node contains only nodes with keys less than the node's key.
    - The right subtree of a node contains only nodes with keys greater than the node's key.
    - Both the left and right subtrees must also be binary search trees.
 */

#include "../include/utils.hpp"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
private:
    bool isValidBSTHelper(TreeNode* root, long long minVal, long long maxVal)
    {
        if(root == NULL) {
            return true;
        }
        if(root->val <= minVal || root->val >= maxVal) {
            return false;
        }
        int left = isValidBSTHelper(root->left, minVal, root->val);
        int right = isValidBSTHelper(root->right, root->val, maxVal);
        return (left && right);
    }
public:
    /**
     * 1st solution: recursive method
     *
     * This problem is special due to integer limit test cases.
     * You should change INT_MIN and INT_MAX into LONG_MIN and LONG_MAX.
     *
     */
    bool isValidBST(TreeNode* root)
    {
        return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
    }

    /**
     * 2nd solution: inorder traversal
     *
     */
    bool isValidBST2(TreeNode* root)
    {
        if(root == NULL) {
            return true;
        }

        stack<TreeNode*> nStack;
        TreeNode* curNode = root;
        TreeNode* preNode = NULL;
        while(curNode) {
            nStack.push(curNode);
            curNode = curNode->left;
        }
        curNode = stack

        return true;
    }
};

int main()
{
    TreeNode* root = new TreeNode(10);
    TreeNode* node1 = new TreeNode(5);
    TreeNode* node2 = new TreeNode(15);
    TreeNode* node3 = new TreeNode(12);
    TreeNode* node4 = new TreeNode(20);
    root->left = node1; root->right = node2;
    node2->left = node3; node2->right = node4;

    Solution obj;
    cout << obj.isValidBST(root) << endl;

    delete root;
    delete node1; delete node2;
    delete node3; delete node4;

    return 0;
}