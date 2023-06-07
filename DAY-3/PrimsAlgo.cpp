//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    int bfs(vector<int>&vis,vector<vector<int>>adj[],int i)
    {
        int sum=0;
        vector<vector<int>>mst(vis.size()-1);
        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>>pq;
        pq.push({{0,i},-1});
        int count=0;
        while(!pq.empty())
        {
            int node=pq.top().first.second;
            int weight=pq.top().first.first;
            int parent=pq.top().second;
            pq.pop();
            if(vis[node])
            continue;
            vis[node]=1;
            sum+=weight;
            int w=weight;
            for(auto x:adj[node])
            {
                int adjNode=x[0];
                weight=x[1];
                if(!vis[adjNode])
                {
                    pq.push({{weight,adjNode},node});
                }
            }
            if(parent!=-1)
            {
                mst[count].push_back(node);
                mst[count].push_back(parent);
                mst[count++].push_back(w);
            }
        }
        return sum;
    }
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int sum=0;
        vector<int>vis(V,0);
        sum+=bfs(vis,adj,0);
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends