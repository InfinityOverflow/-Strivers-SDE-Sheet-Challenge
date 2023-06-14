class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int i=0;
        int e=0,el=INT_MAX,c=0,cl=0;
        while(i<nums.size())
        {
            if(c==0 and nums[i]!=el)
            {
                e=nums[i];
                c++;
            }
            else if(cl==0 and nums[i]!=e)
            {
                el=nums[i];
                cl++;
            }
            else if(nums[i]==e)
            c++;
            else if(nums[i]==el)
            cl++;
            else
            {
                c--;
                cl--;
            }
            i++;
        }
        c=0;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]==e)
            c++;
        }
        vector<int>ans;
        if(c>nums.size()/3)
        ans.push_back(e);
        cl=0;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]==el)
            cl++;
        }
        if(cl>nums.size()/3)
        ans.push_back(el);
        return ans;
    }
};