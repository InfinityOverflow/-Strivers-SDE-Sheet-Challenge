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
        ListNode*ans;
        int carry=0;
        ListNode* l3=new ListNode();
        ans=l3;
        while(l1 and l2)
        {
            l3->val=l1->val+l2->val+carry;
            if(l3->val>9)
            {
                carry=1;
                l3->val=l3->val-10;
            }
            else
            carry=0;
            l1=l1->next;
            l2=l2->next;
            if(l1 and l2)
            {
                l3->next=new ListNode();
                l3=l3->next;
            }
        }
        while(l1)
        {
            l3->next=new ListNode();
            l3=l3->next;
            l3->val=l1->val+carry;
            if(l3->val>9)
            {
                carry=1;
                l3->val=l3->val-10;
            }
            else
            carry=0;
            l1=l1->next;
        }
        while(l2)
        {
            l3->next=new ListNode();
            l3=l3->next;
            l3->val=l2->val+carry;
            if(l3->val>9)
            {
                carry=1;
                l3->val=l3->val-10;
            }
            else
            carry=0;
            l2=l2->next;
        }
        if(carry)
        {
            l3->next=new ListNode();
            l3=l3->next;
            l3->val=carry;
        }
        return ans;
    }
};