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
        int sum = 0;
        TreeNode* pCurr = root;
        TreeNode* pNode = NULL;
        while(pCurr) {
            if(pCurr->right == NULL) {
                sum += pCurr->val;
                pCurr->val = sum;
                pCurr = pCurr->left;
            } else {
                pNode = pCurr->right;
                while(pNode->left && pNode->left != pCurr) {
                    pNode = pNode->left;
                }
                if(pNode->left == NULL) {
                    pNode->left = pCurr;
                    pCurr = pCurr->right;
                } else {
                    pNode->left = NULL;
                    sum += pCurr->val;
                    pCurr->val = sum;
                    pCurr = pCurr->left;
                }
            }

        }
        return root;
    }
};

int main()
{
    TreeNode* root = new TreeNode(2);
    TreeNode* left = new TreeNode(3);
    TreeNode* right = new TreeNode(13);
    root->left = left; root->right = right;
    
    Solution* obj;
    obj.convertBST3(root);
    
    print_tree(root);
    
    delete root;
    delete left;
    delete right;
    
    return 0;
}
