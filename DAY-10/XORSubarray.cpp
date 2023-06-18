int Solution::solve(vector<int> &nums, int b) {
    int n=nums.size(); int ans=0;
    int xo=0;
    unordered_map<int,int>m;
    for(int i=0;i<n;i++)
    {
        xo^=nums[i];
        if(xo==b)
        {
            ans++;
        }
        int x=xo^b;
        if(m.find(x)!=m.end())
        {
            ans+=m[x];
        }
        m[xo]++;
    }
    return ans;
}
