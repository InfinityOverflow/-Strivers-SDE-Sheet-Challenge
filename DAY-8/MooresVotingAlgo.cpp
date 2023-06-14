class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i=0;int el=0,count=0;
        while(i<nums.size())
        {
            if(count==0)
            {
                el=nums[i];
                count++;
                i++;
                continue;
            }
            if(el==nums[i])
            {
                count++;
                i++;
                continue;
            }
            else
            {
                count--;
                i++;
            }
        }
        return el;
    }
};