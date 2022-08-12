/**
 * @brief   Leetcode 145 Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> results;
        postorderTraversalHelper(root, results);
        return results;
    }
private:
    void postorderTraversalHelper(TreeNode* root, vector<int>& results) {
        if(root == nullptr) {
            return;
        }
        postorderTraversalHelper(root->left, results);
        postorderTraversalHelper(root->right, results);
        results.push_back(root->val);
    }

public:
    /**
     * 2nd solution: iterative method
     * 
     * @param root 
     * @return vector<int> 
     */
    vector<int> postorderTraversal2(TreeNode* root) {
        if(root == nullptr) {
            return vector<int>{};
        }
        vector<int> results;
        stack<TreeNode*> sNode;
        TreeNode* node = root;
        TreeNode* lastVisited = nullptr;
        while(node || !sNode.empty()) {
            while(node) {
                sNode.push(node);
                node = node->left;
            }
            node = sNode.top();
            if(node->right && node->right != lastVisited) {
                node = node->right;
            } else {
                sNode.pop();
                results.push_back(node->val);
                lastVisited = node;
                node = nullptr;                
            }
        }
        return results;
    }

    /**
     * 3rd solution: iterative method
     * 
     * @param root 
     * @return vector<int> 
     */
    vector<int> postorderTraversal3(TreeNode* root) {
        if (root == nullptr) {
            return vector<int>{};
        }
        
        stack<TreeNode *> sNode;
        vector<int> res;
        while (root) {
            sNode.push(root);
            root = root->left;
        }
        
        TreeNode *pre = nullptr;
        while (!sNode.empty()) {
            TreeNode *top = sNode.top();
            TreeNode *tmp = top->right;
            if (tmp == pre) {
                sNode.pop();
                res.push_back(top->val);
                pre = top;
            } else {
                while (tmp) {
                    sNode.push(tmp);
                    tmp = tmp->left;
                }
                pre = nullptr;
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

    results= obj.postorderTraversal3(root);
    print_array(results);

    return 0;
}