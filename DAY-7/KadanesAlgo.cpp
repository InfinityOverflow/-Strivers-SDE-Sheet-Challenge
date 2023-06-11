class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int gMax,lMax;
        gMax=lMax=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            lMax=max(nums[i],nums[i]+lMax);
            if(lMax>gMax)
            gMax=lMax;
        }
        return gMax;
    }
};