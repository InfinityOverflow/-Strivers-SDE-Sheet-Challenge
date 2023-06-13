class Solution {
public:
    void sortColors(vector<int>& nums) {
    //  int r=0,w=0,b=0;
    //    if(nums.size()==1)
    //    return;
    //    for(auto x:nums)
    //    {
    //        if(!x)
    //        r++;
    //        else if(x==1)
    //        w++;
    //        else
    //        b++;
    //    }
    //    int i=0;
    //    for(i=0;i<r;i++)
    //    {
    //        nums[i]=0;
    //    }
    //    for(i=r;i<w+r;i++)
    //    {
    //        nums[i]=1;
    //    }
    //    for(i=w+r;i<w+r+b;i++)
    //    {
    //        nums[i]=2;
    //    }
       int l=0,m=0,h=nums.size()-1;
       while(l<=m and m<=h)
       {
           if(nums[m]==0)
           {
               nums[m]=nums[l];
               nums[l]=0;
               m++;
               l++;
               continue;
           }
           if(nums[m]==2)
           {
               nums[m]=nums[h];
               nums[h]=2;
               h--;
               continue;
           }
           m++;
       }

    }
};