/**
 * @brief   Leetcode 92 Reverse Linked List II
 *
 * Reverse a linked list from position m to n. Do it in one-pass.
 * Note: 1 ≤ m ≤ n ≤ length of list.
 */
#include "utils.hpp"

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // cout << "m=" << m << " n=" << endl;
        // unnecessary to reverse
        if(m == n || head->next == NULL) {
            return head;
        }

        ListNode* node = head;
        ListNode* preNodeM = NULL;
        ListNode* nodeM = NULL;
        int i = 1;
        while(i < m) {
            preNodeM = node;
            node = node->next;
            i++;
        }
        nodeM = node;
        ListNode* pre = NULL;
        ListNode* pos = NULL;
        while(i < n) {
            pos = node->next;
            node->next = pre;
            pre = node;
            node = pos;
            i++;
        }
        pos = node->next;
        node->next = pre;
        nodeM->next = pos;

        if(preNodeM == NULL) {
            return node;
        } else {
            preNodeM->next = node;
        }

        return head;
    }
};

int main()
{
    Solution object;
    ListNode* head = new ListNode(1);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(3);
    ListNode* node3 = new ListNode(4);
    ListNode* node4 = new ListNode(5);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    print_linkedlist(head);
    head = object.reverseBetween(head, 2, 4);
    print_linkedlist(head);

    head = object.reverseBetween(head, 2, 5);
    print_linkedlist(head);

    head = object.reverseBetween(head, 1, 3);
    print_linkedlist(head);

    head = object.reverseBetween(head, 1, 5);
    print_linkedlist(head);

    head = object.reverseBetween(head, 3, 3);
    print_linkedlist(head);

    return 0;
}
