class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            int target=-nums[i];
            int low=i+1;
            int high=nums.size()-1;
            while(low<high)
            {
                if(nums[low]+nums[high]==target)
                {
                    vector<int>temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[low]);
                    temp.push_back(nums[high]);
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
                else if(nums[low]+nums[high]>target)
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
        return ans;
    }
};