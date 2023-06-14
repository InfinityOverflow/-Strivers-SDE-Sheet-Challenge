class Solution {
int getPaths(int i,int j,vector<vector<int>>&dp)
{
    if(i==1 and j==1)
    {
        dp[i][j]=1;
        return 1;
    }
    if(i<1 || j<1)
    return dp[i][j]=0;
    int top=0, left=0;
    if(dp[i-1][j]!=-1)
    top=dp[i-1][j];
    else
    top=getPaths(i-1,j,dp);
    if(dp[i][j-1]!=-1)
    left=dp[i][j-1];
    else
    left=getPaths(i,j-1,dp);
    return dp[i][j]=top+left;
}

public:
    int uniquePaths(int m, int n) {
       int c=0;
       vector<vector<int>>dp(m,vector<int>(n,0));
       for(int i=0;i<m;i++)
       {
           for(int j=0;j<n;j++)
           {
               if(i==0 and j==0)
               {
                   dp[i][j]=1;
               }
               else
               {
                   int top =0;int left=0;
                   if(i-1>=0)
                   top=dp[i-1][j];
                   if(j-1>=0)
                   left=dp[i][j-1];
                   dp[i][j]=top+left;
               }
           }
       }
       return dp[m-1][n-1];
    }
};