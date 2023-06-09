string kthPermutation(int n, int k)
{
    vector<int>arr(n);
    int fact=1;
    for(int i=1;i<=n;i++)
    {
        arr[i-1]=i;
        fact*=i;
    }
    k--;
    string ans;
    while(ans.length()!=n)
    {
        fact/=arr.size();
        int index=k/fact;
        ans=ans+to_string(arr[index]);
        arr.erase(arr.begin()+index);
        if(!arr.size())
        break;
        k=k%fact;
    }
    return ans;
}
