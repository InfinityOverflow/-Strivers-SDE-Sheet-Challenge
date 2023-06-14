class Solution {
public:
    double myPow(double x, int n) {
        //return pow(x,n);
        if(n==1)
        return x;
        if(n==0)
        return 1;
        if(n>0)
        {
            double sqr=x*x;
            if(n%2==0)
            {
               return myPow(sqr,n/2);
            }
            else
            {
               return x*myPow(sqr,(n-1)/2);
            }
        }
        else
        {
            double pow;
            if(n!=INT_MIN)
            {
                pow=myPow(x,-n);
                return 1/pow;
            }
            else
            {
                if(x==1||x==-1)
                return 1;
                return 0;
            }
            
        }
    }
};