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
        ListNode* n1 = l1;
        ListNode* n2 = l2;
        ListNode* head = nullptr;
        ListNode* iNode = nullptr;
        int carry = 0;
        while(n1 && n2) {
            int sum = n1->val + n2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            ListNode* node = new ListNode(sum);
            if(head == nullptr) {
                head = node;
            } else {
                iNode->next = node;
            }
            iNode = node;
            n1 = n1->next;
            n2 = n2->next;
        }
        if(n1) {
            while(n1) {
                int sum = carry + n1->val;
                carry = sum / 10;
                sum = sum % 10;
                ListNode* node = new ListNode(sum);
                iNode->next = node;
                iNode = node;
                n1 = n1->next;
            }
        } else if(n2) {
            while(n2) {
                int sum = carry + n2->val;
                carry = sum / 10;
                sum = sum % 10;
                ListNode* node = new ListNode(sum);
                iNode->next = node;
                iNode = node;
                n2 = n2->next;
            }
        }
        if(carry) {
            iNode->next = new ListNode(carry);
        }
        return head;
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
    out = obj.addTwoNumbers(l1, l2);
    print_linkedlist(out);

    // case 2
    in1 = {9, 9, 9, 9, 9, 9, 9};
    l1 = create_linkedlist(in1);
    print_linkedlist(l1);
    in2 = {9, 9, 9, 9};
    l2 = create_linkedlist(in2);
    print_linkedlist(l2);
    out = obj.addTwoNumbers(l1, l2);
    print_linkedlist(out);

    return 0;
}