class Solution {
    void getSubsets(vector<int>nums,vector<vector<int>>&ans,vector<int>temp,int i)
    {
        //sort(temp.begin(),temp.end());
        if(i==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        int t=i;
        while(t+1<nums.size()and nums[t]==nums[t+1])
        {
            t++;
        }
        getSubsets(nums,ans,temp,t+1);
        temp.push_back(nums[i]);
        getSubsets(nums,ans,temp,i+1);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int indx=0;
        vector<int>temp;
        getSubsets(nums,ans,temp,indx);
        //sort(ans.begin(),ans.end());
        return ans;
    }
};