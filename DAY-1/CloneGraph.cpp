#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
    void bfs(Node* node,unordered_map<Node*,Node*>&m)
    {
        Node* New =new Node(node->val);
        m[node]=New;
        for(auto x:node->neighbors)
        {
            if(m.find(x)==m.end())
            bfs(x,m);
        }
    }
    void makeGraph(Node* node,unordered_map<Node*,Node*>&m,vector<int>&vis)
    {
        vis[node->val]=1;
        /*if(m.find(node)==m.end())
        {
            Node* New = new Node(node->val);
            m[node]=New;
        }*/
        Node* New=m[node];
        for(auto x:node->neighbors)
        {
            New->neighbors.push_back(m[x]);
            if(!vis[m[x]->val])
            {
                makeGraph(x,m,vis);
            }
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node)
        return nullptr;
        unordered_map<Node*,Node*>m;
        bfs(node,m);
        int n=m.size();
        vector<int>vis(n+1,0);
        makeGraph(node,m,vis);
        return m[node];
    }
};