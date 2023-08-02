/**
 * @file leetcode141.cpp
 * @brief Leetcode 141 Linked List Cycle
 * @version 0.1
 * @date 2023-07-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "utils.hpp"
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }
        ListNode *prev = head;
        ListNode *post = head->next;
        while (prev && post) {
            prev = prev->next;
            if (post->next) {
                post = post->next->next;
            } else {
                post = NULL;
            }
            if (post == prev) {
                return true;
            }
        }
        return false;
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
    node3->next = node2;

    std::cout << obj.hasCycle(head) << std::endl;
    
    return 0;
}
