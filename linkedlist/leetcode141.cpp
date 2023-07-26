/**
 * @file leetcode141.cpp
 * @brief Leetcode 141 Sort List
 * @version 0.1
 * @date 2023-07-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include "utils.hpp"

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // merge sort
        if ((head == nullptr) || (head->next == nullptr)) {
            return head;
        }
        ListNode *mid = findPivot(head);
        ListNode *head2 = mid->next;
        mid->next = nullptr;
        ListNode *pre = sortList(head);
        ListNode *pos = sortList(head2);
        return merge(pre, pos);
    }
private:
    ListNode *merge(ListNode *pre, ListNode *pos) {
        ListNode *head = new ListNode(-1, nullptr);
        ListNode *node = head;
        while (pre || pos) {
            if ((pre == nullptr) || (pos != nullptr && pre->val > pos->val)) {
                node->next = pos;
                pos = pos->next;
            } else if ((pos == nullptr) || (pre != nullptr && pre->val <= pos->val)) {
                node->next = pre;
                pre = pre->next;
            }
            node = node->next;
        }
        node = head->next;
        delete head;
        return node;
    }
    ListNode *findPivot(ListNode *head) {
        ListNode *fast = head->next;
        ListNode *slow = head;
        while (fast) {
            if (fast->next) {
                fast = fast->next->next;
                slow = slow->next;
            } else {
                fast = nullptr;
            }
        }
        return slow;
    }
};

int main()
{
    Solution obj;
    ListNode* head = new ListNode(3);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(0);
    ListNode* node3 = new ListNode(-4);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node1;

    ListNode* node = obj.sortList(head);
    print_linkedlist(node);
    
    return 0;
}
