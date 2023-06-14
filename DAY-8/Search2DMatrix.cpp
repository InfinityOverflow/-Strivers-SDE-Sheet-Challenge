class Solution {
bool binarySearch(vector<int>v,int target)
{
    int l=0;
    int r=v.size()-1;
    int mid=l+(r-l)/2;
    while(l<=r)
    {
        if(v[mid]==target)
        return true;
        else if(v[mid]>target)
        r=mid-1;
        else
        l=mid+1;
        mid=l+(r-l)/2;
    }
    return false;
}
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int l=0; int r=m-1;
        int mid=l+(r-l)/2;
        if(target<=matrix[0][n-1])
        {
            for(int i=0;i<n;i++)
            {
                if(matrix[0][i]==target)
                return true;
            }
            return false;
        }
        if(target>=matrix[m-1][0])
        {
            for(int i=0;i<n;i++)
            {
                if(matrix[m-1][i]==target)
                return true;
            }
            return false;
        }
        while(l<=r)
        {
            if(matrix[mid][0]<=target and matrix[mid][n-1]>=target)
            {
                return binarySearch(matrix[mid],target);
            }
            else if(matrix[mid][0]> target)
            {
                r=mid-1;
            }
            else if(matrix[mid][n-1]<target)
            {
                l=mid+1;
            }
            mid=l+(r-l)/2;
        }
        return false;
    }
};