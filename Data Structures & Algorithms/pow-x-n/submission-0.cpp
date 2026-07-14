class Solution {
public:
    double myPow(double x, int n) {
        if(n<0){
            x=1/x;
            n=-1* n;
        }
      double ans=1;
        while(n!=0){
            ans=x*ans;
            n=n-1;
        }
        return ans;
    }
};
