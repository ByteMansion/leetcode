/**
 * @brief   This file contains utilities used in other files.
 */
#include <iostream>
#include <vector>
#include <cstdlib>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;
/**
* Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *node) : val(x), next(node) {}
 };

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void print_linkedlist(ListNode* node)
{
    if(node == NULL) {
        cout << "Empty Linked List!" << endl;
    }
    while(node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

template <typename T>
void print_array(const vector<T>& array)
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

template <typename T>
void print_2d_array(const vector<vector<T>>& array)
{
    if(array.empty()) {
        cout << "Empty 2D array!" << endl;
    }
    for(int i = 0; i < array.size(); i++) {
        print_array(array[i]);
    }
}

ListNode* create_linkedlist(vector<int> num)
{
    if(num.empty()) {
        cout << "Empty Linkedlist!" << endl;
        return nullptr;
    }
    ListNode* head = nullptr;
    ListNode* node = nullptr;
    for(auto n : num) {
        ListNode* tNode = new ListNode(n);
        if(head == nullptr) {
            head = tNode;
            node = tNode;
            continue;
        }
        node->next = tNode;
        node = tNode;
    }
    return head;
}

static void preorder(const TreeNode* root)
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
