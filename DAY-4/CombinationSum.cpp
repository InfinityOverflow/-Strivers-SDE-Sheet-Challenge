class Solution {
void getCombinations(vector<int>&candidates,vector<int>temp,vector<vector<int>>&ans,int target,int i)
{
    if(target==0)
    {
        ans.push_back(temp);
        return;
    }
    if(target ==1 || i==candidates.size() || target<candidates[i])
    return;
    getCombinations(candidates,temp,ans,target,i+1);
    temp.push_back(candidates[i]);
    target-=candidates[i];
    getCombinations(candidates,temp,ans,target,i);
}
public:
vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
{
    sort(candidates.begin(),candidates.end());
    vector<vector<int>>ans;
    vector<int>temp;
    getCombinations(candidates,temp,ans,target,0);
    return ans;
}
};