/**
 * @brief   Leetcode 445 Add Two Numbers II
 * 
 */

#include "utils.hpp"

class Solution {
    /**
     * solution 1: reverse list and then calculate
     * 
     */
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if(l1 == nullptr) {
            return l2;
        } else if(l2 == nullptr) {
            return l1;
        }
        ListNode* p1 = reverseList(l1);
        ListNode* p2 = reverseList(l2);
        ListNode* res = addTwoNumbersHelper(p1, p2);
        return reverseList(res);
    }
private:
    ListNode* reverseList(ListNode* head)
    {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        // 7->2->4->3
        ListNode* node = head->next;
        // 7->2<-4<-3
        ListNode* tmp = reverseList(node);
        node->next = head;
        head->next = nullptr;
        return tmp;
    }
    ListNode* addTwoNumbersHelper(ListNode* l1, ListNode* l2)
    {
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

    /**
     * solution 2: calculate in place
     * 
     */
public:
    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
        int count = 0;
        ListNode* head;
        for(head = l1; head; head = head->next) {
            count++;
        }
        for(head = l2; head; head = head->next) {
            count--;
        }
        // l1 points to the longer list
        if(count < 0) {
            swap(l1, l2);
        }
        // last points to the nearest pointer to calculated position
        // the value of last pointer is less than 9
        ListNode* last = head = new ListNode(0);
        head->next = l1;
        for(int i = abs(count); i != 0; i--) {
            if(l1->val != 9) {
                last = l1;
            }
            l1 = l1->next;
        }
        while(l1) {
            int sum = l1->val + l2->val;
            if(sum > 9) {  // carry = 1
                sum -= 10;
                last->val += 1;
                last = last->next;
                while(last != l1) {
                    last->val = 0;
                    last = last->next;
                }
            } else if(sum != 9) {
                last = l1;
            }
            l1->val = sum;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(head->val == 1) {
            return head;
        }
        last = head->next;
        delete head;
        return last;
    }
};

int main()
{
    Solution obj;
    vector<int> nums1, nums2;
    ListNode* l1;
    ListNode* l2;
    ListNode* res;


    // case 1: 7243 + 564 = 7807
    nums1 = {7, 2, 4, 3};
    nums2 = {5, 6, 4};
    l1 = create_linkedlist(nums1);
    l2 = create_linkedlist(nums2);
    res = obj.addTwoNumbers2(l1, l2);
    print_linkedlist(res);

    return 0;
}