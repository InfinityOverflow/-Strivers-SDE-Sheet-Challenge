class Solution {
bool isPalindrome(int l,int r,string s)
{
    while(l<=r)
    {
        if(s[l]!=s[r])
        return false;
        l++;
        r--;
    }
    return true;
}
void getPartition(string s,vector<string>temp,vector<vector<string>>&ans,int i)
{
    if(i==s.length())
    {
        ans.push_back(temp);
        return;
    }
    int t=i;
    for(;t<s.length();t++)
    {
        if(isPalindrome(i,t,s))
        {
            temp.push_back(s.substr(i,t-i+1));
            getPartition(s,temp,ans,t+1);
            temp.pop_back();
        }
    }
}
public:
    vector<vector<string>> partition(string s) 
    {
       vector<vector<string>>ans;
       vector<string>temp;
       getPartition(s,temp,ans,0);
       return ans;

    }
};