#include <bits/stdc++.h> 
vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int>ans;
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++)
    {
        if(q[i][0]==0)
        {
            pq.push(q[i][1]);
        }
        else
        {
            int t=pq.top();
            pq.pop();
            ans.push_back(t);
        }
    }
    return ans;
}
