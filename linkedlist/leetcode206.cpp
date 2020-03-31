/**
 * @brief   Leetcode 206 Reverse Linked list
 *
 * Reverse a singly linked list.
 * Follow up:
 * A linked list can be reversed either iteratively or recursively.
 * Could you implement both?
 */
#include <iostream>
#include "../include/utils.hpp"

using namespace std;

class Solution {
public:
    /**
     * 1st solution: recursive method
     */
    // e.g. head->2->3->4
    ListNode* reverseList(ListNode* head) {
        // basic case
        if(head == NULL || head->next == NULL) {
            return head;
        }
        // newNode->4->3->2
        //                ^
        //                |
        //              head
        ListNode* newNode = reverseList(head->next);

        ListNode* tmp = head->next;
        tmp->next = head;
        head->next = NULL;

        return newNode;
    }

    /**
     * 2nd method: iterative method
     */
    ListNode* reverseList2(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* pos = NULL;
        ListNode* pre = NULL;
        while(head->next != NULL) {
            pos = head->next;
            head->next = pre;
            pre = head;
            head = pos;
        }
        head->next = pre;

        return head;
    }
};

int main()
{
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    head->next = node2;
    node2->next = node3;
    node3->next = node4;

    Solution object;
    print_linkedlist(head);
    head = object.reverseList2(head);
    print_linkedlist(head);

    delete head; delete node2; delete node3; delete node4;

    return 0;
}
