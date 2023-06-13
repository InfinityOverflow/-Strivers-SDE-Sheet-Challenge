#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &interval)
{
    sort(interval.begin(),interval.end());
        int n=interval.size();
        int c=0;
        for(int i=0;i<n-1;i++)
        {
            if(interval[i+1][0]<=interval[i][1])
            {
                interval[i+1][0]=interval[i][0];
                interval[i][0]=-1;
                interval[i+1][1]=max(interval[i][1],interval[i+1][1]);
                c++;
            }
        }
        sort(interval.begin(),interval.end());
        reverse(interval.begin(),interval.end());
        for(;c>0;c--)
        {
            interval.pop_back();
        }
        reverse(interval.begin(),interval.end());
        return interval;
}
