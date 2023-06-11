class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<numRows+1;i++)
        {
            vector<int>temp(i,1);
            if(!ans.size())
            {
                ans.push_back(temp);
                continue;
            }
            for(int j=0;j<i-2;j++)
            {
                int l=ans.size()-1;
                temp[j+1]=ans[l][j]+ans[l][j+1];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};