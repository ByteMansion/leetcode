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
#include <climits>


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

#if 0
    vector<int> inorderTraversal(TreeNode* root)
    {
        if(root == NULL) {
            return vector<int>{};
        }
        vector<int> inorder;
        stack<TreeNode*> nStack;
        TreeNode* curNode = root;

        while(curNode != NULL || !nStack.empty()) {
            while(curNode) {
                nStack.push(curNode);
                curNode = curNode->left;
            }
            curNode = nStack.top();
            nStack.pop();
            inorder.push_back(curNode->val);
            curNode = curNode->right;
        }

        return inorder;
    }
#endif
    /**
     * 2nd solution: based on inorder traversal
     *
     *  Inorder is the most appropriate way to judge a BST,
     *  but not preorder or postorder.
     *  NOTE:
     *  1. How to guarantee all node values of right subtree should be
     *     greater than root value, especially its left subtree values?
     *  2. How to guarantee all node values of left subtree should be less
     *     than root value, especially its right subtree values?
     *  3. The subtrees of each subtree should abide by above 2 rules.
     */
    bool isValidBST2(TreeNode* root)
    {
        if(root == NULL) {
            return true;
        }

        stack<TreeNode*> nStack;
        TreeNode* cur = root;
        int bVal;
        long long int rMinVal = LONG_MIN;
        long long int lMaxVal = LONG_MAX;

        while(cur || !nStack.empty()) {
            while(cur) {
                nStack.push(cur);
                // root node of subtree
                bVal = cur->val;
                if(bVal <= rMinVal || bVal >= lMaxVal) {
                    return false;
                }
                if(cur->left && cur->left->val >= bVal) {
                    return false;
                }
                cur = cur->left;
            }
            cur = nStack.top();
            nStack.pop();
            if(cur->right) {
                rMinVal = cur->val;
                if(!nStack.empty()) {
                    TreeNode* node = nStack.top();
                    lMaxVal = node->val;
                } else {
                    lMaxVal = LONG_MAX;
                }
            }
            cur = cur->right;
        }

        return true;
    }
};

int main()
{
    /**
                10
               /  \
            5       18
           / \     /  \
          3   7   11   20
             / \      /
            6   8    19

     */
    TreeNode* root = new TreeNode(10);
    TreeNode* node1 = new TreeNode(5);
    TreeNode* node2 = new TreeNode(18);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(7);
    TreeNode* node5 = new TreeNode(11);
    TreeNode* node6 = new TreeNode(20);
    TreeNode* node7 = new TreeNode(6);
    TreeNode* node8 = new TreeNode(8);
    TreeNode* node9 = new TreeNode(19);
    root->left = node1;  root->right = node2;
    node1->left = node3; node1->right = node4;
    node2->left = node5; node2->right = node6;
    node4->left = node7; node4->right = node8;
    node6->left = node9;

    Solution obj;
    cout << obj.isValidBST2(root) << endl;
#if 0
    vector<int> inorder = obj.inorderTraversal(root);
    print_array(inorder);
#endif
    delete root;
    delete node1; delete node2;
    delete node3; delete node4;
    delete node5; delete node6;
    delete node7; delete node8;
    delete node9;

    return 0;
}
