/**
 * @brief   Leetcode 142 Linked List Cycle II
 * 
 */
#include "../include/utils.hpp"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) {
            return NULL;
        }
        ListNode* fNode = head->next->next;
        ListNode* sNode = head->next;
        while(fNode != sNode) {
            if(sNode->next) {
                sNode = sNode->next;
            } else {
                return NULL;
            }
            if(fNode->next && fNode->next->next) {
                fNode = fNode->next->next;
            } else {
                return NULL;
            }
        }
        sNode = head;
        while(sNode != fNode) {
            sNode = sNode->next;
            fNode = fNode->next;
        }
        return sNode;
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

    ListNode* node = obj.detectCycle(head);
    cout << node->val << endl;

    return 0;
}