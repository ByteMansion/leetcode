/**
 * @brief   Leetcode 112 Path Sum
 *  Given a binary tree and a sum, determine if the tree has a root-to-leaf
 *  path such that adding up all the values along the path equals the given sum.
 *
 *  Note: A leaf is a node with no children.
 */

#include "../include/utils.hpp"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	/**
     * 1st solution: postorder traversal using recursive method
     *
     * - time complexity: O(n), n is the tree node count
     * - space complexity: O(h), h is height of the tree
     */
    bool hasPathSum(TreeNode* root, int sum) {
        int  curSum = 0;
        bool isExist = false;
        postorderHelper(root, sum, curSum, isExist);
        return isExist;
    }
private:
    void postorderHelper(TreeNode* root, const int sum, int& curSum, bool& isExist) {
        if(root == NULL) {
            return;
        }
        curSum += root->val;
        if(root->left == NULL && root->right == NULL &&
           curSum == sum) {
            isExist = true;
            return;
        }
        postorderHelper(root->left, sum, curSum, isExist);
        postorderHelper(root->right, sum, curSum, isExist);
        curSum -= root->val;
    }

public:
    /**
     * 2nd solution: postorder traversal using non-recursive method
     *
     * - time complexity: O(n), n is the tree node count
     * - space complexity: O(1)
     */
    bool hasPathSum2(TreeNode* root, int sum) {
        bool isExist = false;
        postorderNonrecursive(root, sum, isExist);

        return isExist;
    }
private:
	/**
	 * binary tree postorder traversal
     */
    void postorderNonrecursive(TreeNode* root, const int target, bool& exist) {
        stack<TreeNode*> sTraversal;
        TreeNode* node = root;
        TreeNode* pre = NULL;
        int  sum = 0;

        while(node || !sTraversal.empty()) {
            while(node) {
                sum += node->val;
                sTraversal.push(node);
                node = node->left;
            }
            node = sTraversal.top();

            if(node->right && node->right != pre) {
                node = node->right;
            } else {
                if(node->left == NULL && node->right == NULL &&
                   sum == target) {
                    exist = true;
                    return;
                }
                sum -= node->val;
                sTraversal.pop();
                pre = node;
                node = NULL;
            }
        }
    }
};


int main()
{
    Solution obj;
    int sum;
    bool exist;
    // [5, 4, 8, 11, null, 13, 4, 7, 2, null, null, null, 1]
    TreeNode* root = new TreeNode(5);
    TreeNode* node1 = new TreeNode(4); TreeNode* node2 = new TreeNode(8);
    TreeNode* node3 = new TreeNode(11); TreeNode* node4 = new TreeNode(13);
    TreeNode* node5 = new TreeNode(4); TreeNode* node6 = new TreeNode(7);
    TreeNode* node7 = new TreeNode(2); TreeNode* node8 = new TreeNode(1);

    // construct tree
    root->left = node1; root->right = node2;
    node1->left = node3;
    node3->left = node6; node3->right = node7;
    node2->left = node4; node2->right = node5;
    node5->right = node8;

    // case 1: sum = 22
    sum = 22;
    exist = obj.hasPathSum2(root, sum);
    cout << "sum: " << sum << ", exist: " << exist << endl;

    // case 2: sum = 26
    sum = 26;
    exist = obj.hasPathSum2(root, sum);
    cout << "sum: " << sum << ", exist: " << exist << endl;

    // case 3: sum = 15
    sum = 15;
    exist = obj.hasPathSum2(root, sum);
    cout << "sum: " << sum << ", exist: " << exist << endl;

    return 0;
}

