class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int gmax=0;
        int lmax=0;
        for(auto x:nums)
        {
            gmax=max(lmax,gmax);
            if(x==1)
            lmax++;
            else
            lmax=0;
        }
        gmax=max(lmax,gmax);
        return gmax;
    }
};