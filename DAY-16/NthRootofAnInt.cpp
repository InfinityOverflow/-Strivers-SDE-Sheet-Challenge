int NthRoot(int n, int m) {
  int low =1; int high=m;
  if (m==1 || n==1)
  return m;
  int mid=low+(high-low)/2;
  while(low<=high)
  {
    mid=low+(high-low)/2;
    if(pow(mid,n)==m)
    {
      return mid;
    }
    else if(pow(mid,n)>m)
    {
      high=mid-1;
    }
    else
    low=mid+1;
  }
  return -1;
}