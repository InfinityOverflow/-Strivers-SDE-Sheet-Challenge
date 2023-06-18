class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int t) {
         vector<vector<int>>ans;
         if(nums.size()<4)
         return ans;
        sort(nums.begin(),nums.end());
        for(int j=0;j<nums.size()-3;j++)
        {
            for(int i=j+1;i<nums.size()-2;i++)
            {
            long long int target=(long long int)t-(long long int)(nums[i]+nums[j]);
            int low=i+1;
            int high=nums.size()-1;
            while(low<high)
            {
                if(nums[low]+nums[high]==target)
                {
                    vector<int>temp={nums[j],nums[i],nums[low],nums[high]};
                    ans.push_back(temp);
                    while(low<high-1)
                    {
                        if(nums[low]==nums[low+1])
                        low++;
                        else
                        break;
                    }
                    low++;
                }
                else if((long long int)nums[low]+nums[high]>target)
                {
                    high--;
                }
                else
                low++;
            }
            while(i<nums.size()-3)
            {
                if(nums[i]==nums[i+1])
                {
                    i++;
                }
                else break;
            }
            }
            while(j<nums.size()-4)
            {
                if(nums[j]==nums[j+1])
                {
                    j++;
                }
                else break;
            }
        }
        return ans;
    }
};