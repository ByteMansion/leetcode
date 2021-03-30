/**
 * @brief   两个链表的第一个公共节点
 * 
 */
#include "../include/utils.hpp"

class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int len1 = getLength(pHead1);
        int len2 = getLength(pHead2);
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        if(len1 < len2){
            swap(p1, p2);
        }
        int diff = len1 - len2;
        int i = 0;
        while(i < diff) {
            p1 = p1->next;
            i++;
        }
        while(p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
private:
    int getLength(ListNode* p) {
        int i = 0;
        while(p) {
            i++;
            p = p->next;
        }
        return i;
    }
};

int main()
{
    ListNode* pHead1 = new ListNode(0);
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(3);
    ListNode* p4 = new ListNode(4);
    ListNode* pHead2 = new ListNode(0);
    ListNode* p5 = new ListNode(5);

    pHead1->next = p1; p1->next = p2;
    p2->next = p3; p3->next = p4;

    pHead2->next = p5; p5->next = p3;

    Solution obj;
    ListNode* pCom = obj.FindFirstCommonNode(pHead1, pHead2);
    print_linkedlist(pCom);
    
    return 0;
}