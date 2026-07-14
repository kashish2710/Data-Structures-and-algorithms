class Solution {
public:
    double myPow(double x, int n) {
        if(n<0){
            x=1/x;
            n=- n;
        }
      double ans=1;
        while(n>0){
            if(n&1){
            ans=x*ans;
            }
           x=x*x;
            n>>=1;
        }
        return ans ;
    }
};
