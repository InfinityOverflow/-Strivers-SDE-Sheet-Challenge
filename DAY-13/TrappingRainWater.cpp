class Solution {
public:
    int trap(vector<int>& height) {
        // int leftmax=height[0];
        // int rightmax=height.back();
        // int l=0,r=height.size()-1;
        // O(3N) Approach
        // vector<int>leftmax(height.size()),rightmax(height.size());
        // int m=height[0];
        // for(int i=0;i<height.size();i++)
        // {
        //     m=max(height[i],m);
        //     leftmax[i]=m;
        // }
        // m=height.back();
        // for(int i=height.size()-1;i>=0;i--)
        // {
        //     m=max(m,height[i]);
        //     rightmax[i]=m;
        // }
        // int ans=0;
        // for(int i=1;i<height.size()-1;i++)
        // {
        //     ans+= min(leftmax[i],rightmax[i])-height[i];
        // }
        // return ans;
        //
        // Most optimal Approach
        //
        int n = height.size();
  int left = 0, right = n - 1;
  int res = 0;
  int maxLeft = 0, maxRight = 0;
  while (left <= right) {
    if (height[left] <= height[right]) {
      if (height[left] >= maxLeft) {
        maxLeft = height[left];
      } else {
        res += maxLeft - height[left];
      }
      left++;
    } else {
      if (height[right] >= maxRight) {
        maxRight = height[right];
      } else {
        res += maxRight - height[right];
      }
      right--;
    }
  }
  return res;

    }
};