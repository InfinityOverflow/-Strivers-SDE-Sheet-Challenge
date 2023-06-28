class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        // if(target==nums[0])
        // return 0;
        // if(target==nums[high])
        // return high;
        while(low<=high)
        {
            if(target==nums[low])
            return low;
            if(target==nums[high])
            return high;
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            return mid;
            if(nums[mid]>nums[low] )
            {
                if(nums[low]<=target and nums[mid]>target)
                high=mid-1;
                else
                low=mid+1;
            }
            else
            {
                if(nums[mid]< target and target<=nums[high])
                {
                    low=mid+1;
                }
                else
                high=mid-1;
            }
        }
        return -1;
    }
};