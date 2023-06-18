class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
        return 0;
        int l=1;
        unordered_set<int>s;
        for(auto x:nums)
        {
            s.insert(x);
        }
        unordered_set<int>::iterator it=s.begin();
        for(;it!=s.end();it++)
        {
            int n=*it;
            if(s.find(n-1)!=s.end())
            continue;
            else
            {
                int count=1;
                while(s.find(n+1)!=s.end())
                {
                    count++;
                    n++;
                }
                l=max(l,count);
            }
        }
        return l;
    }
};