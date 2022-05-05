/**
 * @file leetcode21.cpp
 * @brief Merge 2 sorted lists
 * @version 0.1
 * @date 2022-05-05
 */
#include "../include/utils.hpp"

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *node = dummy;
        while(list1 && list2) {
            if (list1->val < list2->val) {
                node->next = list1;
                list1 = list1->next;
            } else {
                node->next = list2;
                list2 = list2->next;
            }
            node = node->next;
        }
        if (list1) {
            node->next = list1;
        }
        if (list2) {
            node->next = list2;
        }
        node = dummy->next;
        delete dummy;
        return node;
    }
};

int main()
{
    Solution obj;
    vector<int> nums1;
    vector<int> nums2;
    ListNode *l1, *l2, *res;

    // case1
    nums1 = {1, 2, 3};
    nums2 = {1, 3, 4};
    l1 = create_linkedlist(nums1);
    l2 = create_linkedlist(nums2);
    res = obj.mergeTwoLists(l1, l2);
    print_linkedlist(res);

    system("pause");
    return 0;
}