/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*d1=headA,*d2=headB;int c=3;
        while(c--)
        {
        while(d1 and d2)
        {
            if(d1==d2)
            {
                return d1;
            }
            d1=d1->next;
            d2=d2->next;
        }
        if(!d1)
        {
            d1=headB;
        }
        if(!d2)
        d2=headA;
    }
    return nullptr;
    }
    
};