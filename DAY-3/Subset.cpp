//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
    vector<int>ans;
    int calcSum(vector<int>arr,int i,int sum)
    {
        if(i==arr.size())
        return sum;
        ans.push_back(calcSum(arr,i+1,sum+arr[i]));
        ans.push_back(calcSum(arr,i+1,sum));
        return INT_MAX;
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        if(!N)
        {
            ans.push_back(0);
            return ans;
        }
        int sum=calcSum(arr,0,0);
        int i=0;
        sort(ans.begin(),ans.end());
        for(auto x:ans)
        {
            if(x==INT_MAX)
            i++;
        }
        while(i--)
        {
            ans.pop_back();
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends