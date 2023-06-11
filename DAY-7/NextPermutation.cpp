class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int i=0;
        int n=a.size();
        int f=-1;
        for(i=n-2;i>=0;i--)
        {
            if(a[i]<a[i+1])
            {
                f=i;
                for(int j=n-1;j>i;j--)
                {
                    if(a[i]<a[j])
                    {
                        swap(a[i],a[j]);
                        reverse(a.begin()+i+1,a.end());
                        break;
                    }
                }
                break;
            }
        }
        
        if(f==-1)
        {
            reverse(a.begin(),a.end());
        }
    }
};