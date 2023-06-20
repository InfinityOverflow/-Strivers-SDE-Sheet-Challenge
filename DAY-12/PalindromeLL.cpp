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
ListNode* reverse(ListNode*head)
{
    
    ListNode*d=nullptr,*n=head;
    while(head)
    {
        n=head->next;
        head->next=d;
        d=head;
        head=n;
    }
    return d;
}
public:
    bool isPalindrome(ListNode* head) {
        if(!head->next)
    return true;
        ListNode*slow=head,*fast=head;
        while(fast and fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*temp=slow->next;
        slow->next=nullptr;
        if(temp)
        temp=reverse(temp);
        slow=head;
        while(slow and temp)
        {
            if(slow->val!=temp->val)
            return false;
            slow=slow->next;
            temp=temp->next;
        }
        while(slow and slow->next)
        {
            if(slow->val!=slow->next->val)
            return false;
            slow=slow->next;
        }
        return true;
    }
};