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
pair<ListNode*,ListNode*> reverse(ListNode*head)
{
    ListNode*end=head,*d;
    ListNode*n=head;
    d=nullptr;
    while(head)
    {
        n=head->next;
        head->next=d;
        d=head;
        head=n;
    }
    return {d,end};
}
public:
    // ListNode* reverseKGroup(ListNode* head, int k) {
    //     ListNode*d=head,*ans=nullptr;
    //     while(d and d->next)
    //     {
    //         if(d==head)
    //         {
    //             int i=k-1;
    //             ListNode*start=d,*end=d;
    //             while(i-- and end)
    //             {
    //                 end=end->next;
    //             }
    //             if(end==nullptr)
    //             break;
    //             ListNode*temp=end->next;
    //             end->next=nullptr;
    //             pair<ListNode*,ListNode*>p=reverse(start);
    //             ans=p.first;
    //             d=p.second;
    //             (d)->next=temp;
    //             continue;
    //         }
    //         ListNode*prev=d;
    //         d=d->next;
    //         int i=k-1;
    //         ListNode*start=d,*end=d;
    //         while(i-- and end)
    //         {
    //             end=end->next;
    //         }
    //         if(end==nullptr)
    //         break;
    //         ListNode*temp=end->next;
    //         end->next=nullptr;
    //         pair<ListNode*,ListNode*>p=reverse(start);
    //         prev->next=p.first;
    //         d=p.second;
    //         d->next=temp;
    //     }
    //     return ans;
    // }
    	ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cursor = head;
        for(int i = 0; i < k; i++){
            if(cursor == nullptr) return head;
            cursor = cursor->next;
        }
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;
        for(int i = 0; i < k; i++){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};