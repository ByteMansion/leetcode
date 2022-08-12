/**
 * @file leetcode147.cpp
 * @brief Sort (Linked list version)
 * @version 0.1
 * @date 2022-05-05
 * 
 */
#include "utils.hpp"
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
    ListNode* insertionSortList(ListNode* head) {
        if ((head == nullptr) || (head->next == nullptr)) {
            return head;
        }

        // dummy node for head insertion
        ListNode *sentinel = new ListNode(-1);
        sentinel->next = head;

        // pointer for iterating sorted elements
        ListNode *itr_pre;
        ListNode *itr;
        // pointer to element waiting for sort
        ListNode *tgt = head->next;
        // previous pointer to element waiting for sort
        ListNode *tgt_pre = head;
        while (tgt) {
            itr = head;
            itr_pre = sentinel;
            while (itr != tgt && tgt->val >= itr->val) {
                itr_pre = itr;
                itr = itr->next;
            }
            if (itr == tgt) {
                // don't move
                tgt_pre = tgt;
                tgt = tgt->next;
            } else {
                // insert into sorted elements
                tgt_pre->next = tgt->next;
                itr_pre->next = tgt;
                tgt->next = itr;
                tgt = tgt_pre->next;

                head = sentinel->next;
            }
        }
        delete sentinel;
        return head;
    }
};

int main()
{
    Solution obj;
    vector<int> nums;
    ListNode *head;
    ListNode *res;
    
    //case 1
    nums = {6, 5, 3, 1, 8, 7, 2, 4};
    head = create_linkedlist(nums);
    print_linkedlist(head);
    res = obj.insertionSortList(head);
    print_linkedlist(res);

    system("pause");
    return 0;
}