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
#include <climits>

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
     *  space complexity: if the depth of trees is ds and dt,
     *   the stack space complexity is O(max{ds, dt}) at any time.
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

    /**
     * 3rd solution: traversal + KMP
     *
     *  This method will be divided into 2 steps:
     *  1. reconstruct each tree into a full binary tree  
     *  2. verify if t's traversal is the substring of s'
     *
     */
public:
    int maxVal;
    int lNull, rNull;
    vector<int> sPreorder;
    vector<int> tPreorder;

    void getMaxElement(TreeNode* root) {
        if(!root) {
            return;
        }

        if(root->val > maxVal) {
            maxVal = root->val;
        }
        getMaxElement(root->left);
        getMaxElement(root->right);
    }

    // preorder traversal and change tree into a full binary tree
    void dfsHelper(TreeNode* root, vector<int>& order) {
        if(root) {
            order.push_back(root->val);
        }

        if(root->left) {
            dfsHelper(root->left, order);
        } else {
            order.push_back(lNull);
        }

        if(root->right) {
            dfsHelper(root->right, order);
        } else {
            order.push_back(rNull);
        }
    }
#if 0
    // consider negative number if using rabin-karp algorithm
    bool rabin_karp(vector<int>& sPreorder, vector<int>& tPreorder) {

    }
#endif
    vector<int> computePrefixFunc(vector<int> v) {
        int len = v.size();
        vector<int> pi(len, 0);  // prefix function
        int k = 0;

        for(int q = 2; q < len; q++) {
            while(k > 0 && v[k+1] != v[q]) {
                k = pi[k];
            }
            if(v[k+1] == v[q]) {
                k += 1;
            }
            pi[q] = k;
        }

        return pi;
    }
    bool kmp(vector<int> sArray, vector<int> tArray) {
        int sLen = sArray.size();
        int tLen = tArray.size();
        int q = 0;

        // preprocess: get prefix function
        vector<int> pi = computePrefixFunc(tArray);

        for(int i = 1; i < sLen; i++) {
            while(q > 0 && tArray[q+1] != sArray[i]) {
                q = pi[q];
            }
            if(tArray[q+1] == sArray[i]) {
                q += 1;
            }
            if(q == tLen - 1) {
                return true;
            }
        }
        return false;
    }

    bool isSubtree3(TreeNode* s, TreeNode* t) {
        maxVal = INT_MIN;
        getMaxElement(s);
        getMaxElement(t);

        lNull = maxVal + 1;
        rNull = maxVal + 2;

        dfsHelper(s, sPreorder);
        dfsHelper(t, tPreorder);

        // return rabin_karp(sPreorder, tPreorder);
        return kmp(sPreorder, tPreorder);
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
    bool result = obj.isSubtree3(&sroot, &troot);
    cout << result << endl;

    return 0;
}
