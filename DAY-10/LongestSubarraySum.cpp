#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& nums, int k){
    int n=nums.size();
    unordered_map<int,int>m;
    int sum=0;int len=0;
    for(int i=0;i<n;i++)
    {
        sum+=nums[i];
        if(sum==k)
        {
            len=max(len,i+1);
        }
        int x=sum-k;
        if(m.find(x)!=m.end())
        {
           len=max(len,i-m[x]);
        }
        if(m.find(sum)!=m.end())
        {
            continue;
        }
        else
        m[sum]=i;
    }
    return len;
}