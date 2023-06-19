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
void recursion(ListNode* head)
{
    if(head->next==nullptr)
    {
        return;
    }
    recursion(head->next);
    ListNode*temp=head;
    head=head->next;
    head->next=temp;
}
public:
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*>s;
        s.push(nullptr);
        while(head!=nullptr)
        {
            s.push(head);
            ListNode * temp=(*head).next;
            (*head).next=nullptr;
            head=temp;
        }
        ListNode*ans=s.top();
        head=s.top();
        while(head!=nullptr and !s.empty())
        {
            s.pop();
            (*head).next=s.top();
            head=(*head).next;
        }
        return ans;
    }
};