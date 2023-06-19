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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*start=head;
        int count =0;
        while(head!=nullptr)
        {
            count++;
            head=head->next;
        }
        head=start;
        vector<ListNode*>v(count,nullptr);
        int i=0;
        while(head!=nullptr)
        {
            v[i]=head;
            head=head->next;
            i++;
        }
        if(n==1)
        {
            if(count!=1)
            v[count-2]->next=nullptr;
            else
            v[0]=nullptr;
            return v[0];
        }
        if(n==count)
        {
            return v[1];
        }
        else
        n=count-n;
        v[n-1]->next=v[n+1];
        return v[0];
    }
};