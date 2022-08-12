/**
 * @brief   Leetcode 144 Binary Tree Preorder Traversal
 * 
 * 
 */
#include "utils.hpp"
#include <stack>


class Solution {
public:
    /**
     * 1st solution: recursive method
     * 
     * @param root 
     * @return vector<int> 
     */
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> results;
        preorderTraversalHelper(root, results);
        return results;
    }
private:
    void preorderTraversalHelper(TreeNode* root, vector<int>& results) {
        if(root == nullptr) {
            return;
        }
        results.push_back(root->val);
        preorderTraversalHelper(root->left, results);
        preorderTraversalHelper(root->right, results);
    }

public:
    /**
     * 2nd solution: iterative method
     * 
     * @param root 
     * @return vector<int> 
     */
    vector<int> preorderTraversal2(TreeNode* root) {
        if(root == nullptr) {
            return vector<int>{};
        }
        stack<TreeNode*> sNode;
        vector<int> results;
        TreeNode* node = nullptr;
        sNode.push(root);
        while(!sNode.empty()) {
            node = sNode.top();
            results.push_back(node->val);
            sNode.pop();
            if(node->right) {
                sNode.push(node->right);
            }
            if(node->left) {
                sNode.push(node->left);
            }
        }
        return results;
    }

    /**
     * 3rd solution: iterative method
     * This solution is similar to the 2nd.
     * 
     * @param root 
     * @retval an array of value in preoder
     */
    vector<int> preorderTraversal3(TreeNode *root) {
        if (root == nullptr) {
            return vector<int>{};
        }

        stack<TreeNode *> sNode;
        vector<int> res;
        while (root) {
            res.push_back(root->val);
            sNode.push(root);
            root = root->left;
        }
        while (!sNode.empty()) {
            TreeNode *node = sNode.top();
            sNode.pop();
            TreeNode *t = node->right;

            while (t) {
                sNode.push(t);
                res.push_back(t->val);
                t = t->left;
            }
        }
        
        return res;
    }
};

int main()
{
    Solution obj;
    vector<int> results;

    // case 1
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

    results= obj.preorderTraversal3(root);
    print_array(results);

    return 0;
}