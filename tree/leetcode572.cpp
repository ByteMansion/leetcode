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
#include <vector>
#include <iostream>

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
    int getHeight(TreeNode* root) {
        // based on level traversal
        int height = -1;
        queue<TreeNode*> qNode;
        qNode.push(root);
        TreeNode* node = root;
        while(!qNode.empty()) {
            queue<TreeNode*> level;
            while(!qNode.empty()) {
                node = qNode.front();
                qNode.pop();
                if(node->left) {
                    level.push(node->left);
                }
                if(node->right) {
                    level.push(node->right);
                }
            }
            qNode = level;
            height++;
        }
        return height;
    }
public:
	/**
     * 1st solution: based on traversal
     *  This method is low efficiency.
     *
     *  NOTE: The solution can be accepted if we just get 2 traversals,
     *  but it is not enough to solve this problem completely.
     *  For example:
           s:  3         t:   4
             /   \           /
            4     4         4
           / \               \
          4   4               4
     *
     *  Therefore, we should add one more condition: height of the subtree.
     *
     *  time complexity: O(|s| * |t|)
           time complexity of each traversal is O(|t|) and
           space complexity is O(|t|). In this method, we need to traverse
           tree t 3 times and then compare traversal results with each subtree 
           of tree s.
     * space complexity: O(|s| + |t|)
     *
     */
    bool isSubtree(TreeNode* s, TreeNode* t) {
        // preorder and inorder traversal of tree t
        vector<int> tPreorder = preorder(t);
        vector<int> tInorder = inorder(t);
        int tHeight = getHeight(t);
        // cout << "tHeight " << tHeight << endl;

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
                    int sHeight = getHeight(sCur);
                    if(sHeight == tHeight && sPreorder == tPreorder && sInorder == tInorder) {
                        // cout << "Height " << sHeight << endl;
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

    /**
     * 2nd solution: using recursive method
     *
     *  time complexity: O(|s| * |t|)
     *  space complexity: O(max{|s|, |t|})
     *
     */
private:
    bool check(TreeNode* s, TreeNode* t) {
        if(!s && !t) {
            return true;
        }
        if((s && !t) || (!s && t) || (s->val != t->val)) {
            return false;
        }

        return check(s->left, t->left) && check(s->right, t->right);
    }

public:
    bool isSubtree2(TreeNode* s, TreeNode* t) {
        if(check(s, t))
            return true;

        bool left = false;
        bool right = false;
        if(s->left) {
            left = isSubtree(s->left, t);
        }
        if(s->right) {
            right = isSubtree(s->right, t);
        }

        return (left || right);
    }
};

int main()
{
    TreeNode sroot(3);
    TreeNode node1(4); TreeNode node2(4);
    TreeNode node3(4); TreeNode node4(4);
    sroot.left = &node1; sroot.right = &node2;
    node1.left = &node3; node1.right = &node4;

    TreeNode troot(4);
    TreeNode node5(4); TreeNode node6(4);
    troot.left = &node5; node5.right = &node6;

    Solution obj;
    bool result = obj.isSubtree2(&sroot, &troot);
    cout << result << endl;

    return 0;
}
