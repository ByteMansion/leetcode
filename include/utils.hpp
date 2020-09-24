/**
 * @brief   This file contains utilities used in other files.
 */
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
/**
* Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
 };

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void print_linkedlist(ListNode* head)
{
    if(head == NULL) {
        cout << "Empty Linked List!" << endl;
    }
    ListNode* node = head;
    while(node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

void print_array(const vector<int> &array)
{
    if(array.empty() || array.size() <= 0) {
        cout << "[This array is empty!]" << endl;
        return;
    }

    size_t cnt = array.size();
    for(size_t index = 0; index < cnt; index++) {
        cout << array[index] << " ";
    }
    cout << endl;
}

static void preorder(const Treenode* root)
{
    if(root == nullptr) {
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
void print_tree(const TreeNode* root)
{
    if(root == nullptr) {
        cout << "[This tree is empty!]" << endl;
        return;
    }
    preorder(root);
    cout << endl;
}
