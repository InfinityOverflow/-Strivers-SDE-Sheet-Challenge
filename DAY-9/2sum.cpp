class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>temp;
        for(auto x:nums)
        {
            temp.push_back(x);
        }
        sort(nums.begin(),nums.end());
        vector<int>ans;
        int i=0;int j=nums.size()-1;
        while(i<j)
        {
            if(nums[i]+nums[j]==target)
            {
                ans.push_back(nums[i]);
                ans.push_back(nums[j]);
                break;
            }
            else if(nums[i]+nums[j]>target)
            {
                j--;
            }
            else
            i++;
        }
        int flag=0;int check=0;
        for(i=0;i<temp.size();i++)
        {
            if(temp[i]==ans[0] and flag==0)
            {
                flag++;
                ans[0]=i;
            }
            else if(temp[i]==ans[1]and check==0)
            {
                check++;
                ans[1]=i;
            }
        }
        return ans;
    }
};