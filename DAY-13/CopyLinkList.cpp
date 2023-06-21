/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>umap;
        Node*slow=head;
        while(slow)
        {
            Node*temp=new Node(slow->val);
            umap[slow]=temp;
            slow=slow->next;
        }
        slow=head;
        Node*ans;
        while(slow)
        {
            ans=umap[slow];
            ans->next=umap[slow->next];
            ans->random=umap[slow->random];
            ans=ans->next;
            slow=slow->next;
        }
        return umap[head];
    }
};