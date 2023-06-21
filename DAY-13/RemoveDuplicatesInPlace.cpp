class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0; int j=-1;
        for(;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                continue;
            }
            else
            {
                swap(nums[++j],nums[i]);
            }
        }
        swap(nums[++j],nums[i]);
        return j+1;
    }
};