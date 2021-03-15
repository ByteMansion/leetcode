/**
 * @brief   Leetcode 2: Add Two Numbers
 *
 *  You are given two non-empty linked lists representing two non-negative integers.
 *  The digits are stored in reverse order, and each of their nodes contains a single
 *  digit. Add the two numbers and return the sum as a linked list.
 *
 *  You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 *  Example 1:
 *  2->4->3, 5->6->4  ==>>  7->0->8
 *  Input: l1 = [2,4,3], l2 = [5,6,4]
 *  Output:[7,0,8]
 *  Explanation: 342 + 465 = 807.
 *
 *  Example 2:
 *  Input: l1 = [0], l2 = [0]
 *  Output: [0]
 *
 *  Example 3:
 *  Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 *  Output: [8,9,9,9,0,0,0,1]
 */

#include "../include/utils.hpp"
#include <iostream>

using namespace std;

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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) {
            return l2;
        } else if(l2 == nullptr) {
            return l1;
        }
        ListNode* pHead = new ListNode(-1);
        ListNode* node = pHead;
        int v1, v2;
        int carry = 0;
        while(l1 || l2) {
            if(l1) {
                v1 = l1->val;
                l1 = l1->next;
            } else {
                v1 = 0;
            }
            if(l2) {
                v2 = l2->val;
                l2 = l2->next;
            } else {
                v2 = 0;
            }
            int sum = v1 + v2 + carry;
            int digit = sum % 10;
            carry = sum / 10;
            node->next = new ListNode(digit);
            node = node->next;
        }
        if(carry) {
            node->next = new ListNode(carry);
        }
        node = pHead->next;
        delete pHead;
        return node;
    }
};
int main()
{
    Solution obj;
    vector<int> in1;
    vector<int> in2;
    ListNode* out;
    ListNode* l1;
    ListNode* l2;

    // case 1
    in1 = {2, 4, 3};
    l1 = create_linkedlist(in1);
    print_linkedlist(l1);
    in2 = {5, 6, 4};
    l2 = create_linkedlist(in2);
    print_linkedlist(l2);
    out = obj.addTwoNumbers2(l1, l2);
    print_linkedlist(out);

    // case 2
    in1 = {9, 9, 9, 9, 9, 9, 9};
    l1 = create_linkedlist(in1);
    print_linkedlist(l1);
    in2 = {9, 9, 9, 9};
    l2 = create_linkedlist(in2);
    print_linkedlist(l2);
    out = obj.addTwoNumbers2(l1, l2);
    print_linkedlist(out);

    return 0;
}
