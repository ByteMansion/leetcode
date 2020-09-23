/**
 * @brief   Leetcode 538 Convert BST to Greater Tree
 * Given a Binary Search Tree (BST), convert it to a Greater Tree such that every 
 * key of the original BST is changed to the original key plus sum of all keys 
 * greater than the original key in BST.
 *
 */
#include "../include/utils.hpp"
#include <iostream>
#include <stack>
#include <vector>

class Solution {
public:
    /**
     * 1st solution: recursive method
     *
     * Using reverse inorder traversal
     */
    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr) {
            return nullptr;
        }
        convertBST(root->right);
        sum += root->val;
        root->val = sum;
        convertBST(root->right);
        return root;
    }
private:
    int sum = 0;

public:
    /**
     * 2nd solution: non-recursive method
     *
     * Using reverse inorder traversal
     */
    TreeNode* convertBST2(TreeNode* root) {
        stack<TreeNode*> sTree;
        TreeNode* pNode = root;

        while(pNode || !sTree.empty()) {
            while(pNode) {
                sTree.push(pNode);
                pNode = pNode->right;
            }
            pNode = sTree.top();
            sTree.pop();
            sum += pNode->val;
            pNode->val = sum;
            pNode = pNode->left;
        }
        return root;
    }

public:
    /**
     * 3rd solution: Morris algorithm
     *
     */
    TreeNode* convertBST3(TreeNode* root) {
        
    }
};

int main()
{
    
}
