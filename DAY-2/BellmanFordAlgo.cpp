//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<pair<int,int>>adj[V];
        int src=S;
        for(auto x: edges)
        {
            adj[x[0]].push_back({x[1],x[2]});
        }
        vector<int>dist(V,1e8);
        dist[src]=0;
        for(int i=0;i<V-1;i++)
        {
            for(auto x:edges)
            {
                if(dist[x[0]]==INT_MAX)
                {
                    continue;
                }
                if(dist[x[0]]+x[2]<dist[x[1]])
                {
                    dist[x[1]]=dist[x[0]]+x[2];
                }
            }
        }
        int flag=0;
        for(auto x:edges)
        {
            if(dist[x[0]]+x[2]<dist[x[1]])
            {
                flag++;
            }
        }
        if(flag)
        {
            vector<int>a(1,-1);
            return a;
        }
        return dist;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
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

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends