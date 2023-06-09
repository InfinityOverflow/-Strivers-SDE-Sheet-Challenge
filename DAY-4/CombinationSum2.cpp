class Solution {
void getComb(vector<int>candidates,vector<int>temp,vector<vector<int>>&ans,int target,int i)
{
    if(target==0)
    {
        ans.push_back(temp);
        return;
    }
    if(i==candidates.size()||target<candidates[i])
    {
        return;
    }
    int t=i;
    while(t+1<candidates.size() and candidates[t]==candidates[t+1])
    {
        t++;
    }
    getComb(candidates,temp,ans,target,t+1);
    temp.push_back(candidates[i]);
    target-=candidates[i];
    getComb(candidates,temp,ans,target,i+1);
}
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        getComb(candidates,temp,ans,target,0);
        return ans;
    }
};