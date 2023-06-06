//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) 
    {
        vector<int>parent(n+1,0);
        for(int i=1;i<n;i++)
        {
            parent[i]=i;
        }
        vector<pair<int,int>>adj[n+1];
        for(auto x:edges)
        {
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        vector<int>dist(n+1,INT_MAX);
        int src=1;
        dist[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});
        while(!pq.empty())
        {
            int node=pq.top().second;
            int dis=pq.top().first;
            pq.pop();
            for(auto x:adj[node])
            {
                int adjNode=x.first;
                int edgeWeight=x.second;
                if(dis+edgeWeight<dist[adjNode])
                {
                    dist[adjNode]=edgeWeight +dis;
                    pq.push({dist[adjNode],adjNode});
                    parent[adjNode]=node;
                }
            }
        }
        vector<int>ans;
        if(dist[n]==INT_MAX)
        {
            ans.push_back(-1);
            return ans;
        }
        int i=n;
        while(parent[i]!=i)
        {
            ans.push_back(i);
            i=parent[i];
        }
        ans.push_back(src);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends