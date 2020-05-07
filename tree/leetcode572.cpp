/**
 * @brief   Leetcode 572: Subtree of Another Tree
 *  Given two non-empty binary trees s and t, check whether tree t
 *  has exactly the same structure and node values with a subtree of s.
 *  A subtree of s is a tree consists of a node in s and all of this node's descendants.
 *  The tree s could also be considered as a subtree of itself.
 */
#include "../include/utils.hpp"
#include <stack>
#include <queue>

using namespace std;

class Solution {
private:
    vector<int> preorder(TreeNode* root) {
        stack<TreeNode*> sPreorder;
        vector<int> result;
        TreeNode* node = root;
        sPreorder.push(node);
        while(!sPreorder.empty()) {
            node = sPreorder.top();
            sPreorder.pop();
            result.push_back(node->val);
            if(node->right) {
                sPreorder.push(node->right);
            }
            if(node->left) {
                sPreorder.push(node->left);
            }
        }
        return result;
    }
    vector<int> inorder(TreeNode* root)
    {
        if(root == NULL) {
            return vector<int>{};
        }
        vector<int> inorder;
        stack<TreeNode*> nStack;
        nStack.push(root);
        TreeNode* curNode = root;
        TreeNode* preNode = NULL;

        while(!nStack.empty()) {
            while(curNode->left && curNode != preNode) {
                curNode = curNode->left;
                nStack.push(curNode);
            }
            curNode = nStack.top();
            nStack.pop();
            inorder.push_back(curNode->val);
            preNode = curNode;

            if(curNode->right) {
                curNode = curNode->right;
                nStack.push(curNode);
            }
        }

        return inorder;
    }
public:
	/**
     * 1st solution: based on traversal
     *  this method is low efficiency.
     */
    bool isSubtree(TreeNode* s, TreeNode* t) {
        // preorder and inorder traversal
        // 2 traversals can determine a unique tree
        vector<int> tPreorder = preorder(t);
        vector<int> tInorder = inorder(t);

        // level traversal
        queue<TreeNode*> sQueue;
        sQueue.push(s);
        TreeNode* sCur = s;
        while(!sQueue.empty()) {
            queue<TreeNode*> level;
            while(!sQueue.empty()) {
                sCur = sQueue.front();
                sQueue.pop();
                if(sCur->val == t->val) {
                    vector<int> sPreorder = preorder(sCur);
                    vector<int> sInorder = inorder(sCur);
                    if(sPreorder == tPreorder && sInorder == tInorder) {
                        return true;
                    }
                }
                if(sCur->left) {
                    level.push(sCur->left);
                }
                if(sCur->right) {
                    level.push(sCur->right);
                }
            }
            sQueue = level;
        }
        return false;
    }
};

int main()
{


    return 0;
}
