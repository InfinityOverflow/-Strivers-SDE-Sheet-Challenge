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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)
        return head;
        int n=0;
         ListNode*slow=head;
            while(slow->next)
            {
                slow=slow->next;
                n++;
            }
            n++;
            slow->next=head;
            k%=n;
            for(int i=0;i<n-k;i++)
            {
                slow=slow->next;
            }
            head=slow->next;
            slow->next=nullptr;
        return head;
    }
};