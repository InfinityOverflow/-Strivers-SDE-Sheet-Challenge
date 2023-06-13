class Solution {
void rot(vector<vector<int>>&m,int i,int j,int n)
{
    int temp=m[i][n-1-j];
    m[i][n-1-j]=m[i][j];
    swap(m[n-i-1][n-1-j],temp);
    swap(m[n-i-1][j],temp);
    swap(m[i][j],temp);
}
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};