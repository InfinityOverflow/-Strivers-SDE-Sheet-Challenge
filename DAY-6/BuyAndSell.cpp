class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=INT_MAX;
        int m=0;
        for(auto x:prices)
        {
            if(min>x)
            {
                min=x;
            }
            m=max(x-min,m);
        }
        return m;
    }
};