class Solution {
bool dfs(int i,vector<int>&vis,vector<int>&pvis,vector<vector<int>>&adj)
{
    pvis[i]=vis[i]=1;
    for(auto x:adj[i])
    {
        if(pvis[x])
        return true;
        if(!pvis[x] and !vis[x])
        {
            if(dfs(x,vis,pvis,adj))
            return true;
            //pvis[x]=0;
        }
    }
    pvis[i]=0;
    return false;
}
public:
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        vector<vector<int>>adj(numCourses);
        int n=prereq.size();
        for(int i=0;i<n;i++)
        {
            adj[prereq[i][1]].push_back(prereq[i][0]);
        }
        vector<int>vis(numCourses,0);
        
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                vector<int>pvis(numCourses,0);
                if(dfs(i,vis,pvis,adj))
                return false;
            }
        }
        return true;
    }
};