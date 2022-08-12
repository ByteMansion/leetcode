/**
 * @file leetcode148.cpp
 * @brief Leetcode 148 Sort List
 * 
 */
#include "utils.hpp"

class Solution {
public:
    /**
     *  Selection Sort (1): swap the nodes
     * 
     *  There are 2 ways to get a sorted linked list:change the link
     *  of nodes, or swap the values.
     * 
     * time complexity: O(n^2)
     * Exceeds time limit
     */
    ListNode* sortList(ListNode* head) 
    {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* pRes = new ListNode(-1);
        pRes->next = head;
        ListNode* pIter = head;
        ListNode* pEnd = nullptr;  // tail node of sorted part
        ListNode* pFound = nullptr;  // node with maximum value in unsorted part
        ListNode* pPreFound = nullptr;   // previous node of the maximum node
        int maxVal = INT_MIN;
        while(pIter) {
            // default start node
            maxVal = pIter->val;
            pFound = pIter;
            pPreFound = nullptr;
            // Iterator should start from        
            ListNode* pNode = pIter->next;
            ListNode* pPrev = pIter;
            while(pNode) {
                if(maxVal < pNode->val) {
                    maxVal = pNode->val;
                    pFound = pNode;
                    pPreFound = pPrev;
                }
                pPrev = pNode;
                pNode = pNode->next;
            }
            if(pEnd == nullptr) {
                pEnd = pFound;
            }
            if(pPreFound) {
                // the maximum node isn't the head of unsorted part
                pPreFound->next = pFound->next;
            } else {
                // the maximum node is the head of unsorted part
                pIter = pIter->next;
                pEnd->next = pIter;
            }
            // set found node as head
            pFound->next = pRes->next;
            pRes->next = pFound;
        }
        head = pRes->next;
        delete pRes;
        return head;
    }

    /**
     * Selection Sort (2): Swap the values
     * 
     * time complexity: O(n^2)
     * Exceeds time limit
     */
    ListNode* sortList2(ListNode* head) 
    {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* pNode = head;
        while(pNode) {
            int minVal = pNode->val;
            ListNode* pFound = pNode;
            ListNode* pIter = pNode->next;
            while(pIter) {
                if(minVal > pIter->val) {
                    pFound = pIter;
                    minVal = pIter->val;
                }
                pIter = pIter->next;
            }
            swap(pNode->val, pFound->val);
            pNode = pNode->next;
        }
        return head;
    }
    /**
     * Insertion Sort
     * 
     * time complexity: O(n^2)
     * Exceeds time limit
     */
    ListNode* sortList3(ListNode* head)
    {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* pRes = new ListNode(-1);
        pRes->next = head;
        ListNode* pEnd = head;
        ListNode* pNode = head->next;
        while(pNode) {
            ListNode* pPrev = pRes;
            ListNode* pIter = pRes->next;
            while(pIter != pNode && pNode->val > pIter->val) {
                pPrev = pIter;
                pIter = pIter->next;
            }

            if(pIter != pNode) {
                pEnd->next = pNode->next;
                pPrev->next = pNode;
                pNode->next = pIter;
                pNode = pEnd->next;
            } else {
                pEnd = pNode;
                pNode = pNode->next;
            }
        }
        head = pRes->next;
        delete pRes;
        return head;
    }
    /**
     * Merge Sort
     * 
     * time complexity: O(nlogn)
     */
    ListNode* sortList4(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *d_lft = new ListNode(-1);
        ListNode *d_rgt = new ListNode(-1);
        ListNode *lft = d_lft, *rgt = d_rgt;
        while (head) {
            lft->next = head;
            lft = lft->next;
            head = head->next;
            if (head) {
                rgt->next = head;
                rgt = rgt->next;
                head = head->next;    
            }
        }
        lft->next = nullptr;
        lft = d_lft->next;
        rgt->next = nullptr;
        rgt = d_rgt->next;
        delete d_lft; delete d_rgt;
        ListNode *node1 = sortList4(lft);
        ListNode *node2 = sortList4(rgt);
        return merge(node1, node2);
    }
private:
    ListNode* merge(ListNode* left, ListNode* right)
    {
        ListNode* head = new ListNode(-1);
        ListNode* pNode = head;
        while(left && right) {
            if(left->val > right->val) {
                pNode->next = right;
                right = right->next;
            } else {
                pNode->next = left;
                left = left->next;
            }
            pNode = pNode->next;
        }
        if(left) {
            pNode->next = left;
        }
        if(right) {
            pNode->next = right;
        }
        pNode = head->next;
        delete head;
        return pNode;
    }

public:
    /**
     * Quick Sort
     * 
     * worst time complexity: O(n^2)
     * Exceeds time limit
     */
    ListNode* sortList5(ListNode* head)
    {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* pRes = new ListNode(-1);
        pRes->next = head;
        quick(pRes, head, nullptr);
        head = pRes->next;
        delete pRes;
        return head;
    }
private:
    void quick(ListNode* preHead, ListNode* head, ListNode* end)
    {
        if(head == end || head->next == end) {
            return;
        }
        ListNode* pNode = head;
        ListNode* pIter = head->next;
        ListNode* pPrev = head;
        while(pIter != end) {
            if(pIter->val < pNode->val) {
                pPrev->next = pIter->next;
                pIter->next = preHead->next;
                preHead->next = pIter;
                pIter = pPrev->next;
            } else {
                pPrev = pIter;
                pIter = pIter->next;
            }
        }
        quick(preHead, preHead->next, pNode);
        quick(pNode, pNode->next, end);
    }
};

int main()
{
    Solution obj;
    vector<int> nums;
    ListNode* head;

    // case 1
    nums = {4, 2, 1, 3};
    head = create_linkedlist(nums);
    print_linkedlist(obj.sortList5(head));

    // case 2
    nums = {3, 5, 9, 7, 2, 0, 6};
    head = create_linkedlist(nums);
    print_linkedlist(obj.sortList5(head));

    // case 3
    nums = {3, 1, 8};
    head = create_linkedlist(nums);
    print_linkedlist(obj.sortList5(head));

    return 0;
}