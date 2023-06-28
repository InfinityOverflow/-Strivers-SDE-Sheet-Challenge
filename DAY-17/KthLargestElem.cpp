class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(),nums.end());
        int ans=0;
        while(k--)
        {
            pop_heap(nums.begin(),nums.end());
            ans=nums.back();
            nums.pop_back();
        }
        return ans;
    }
};