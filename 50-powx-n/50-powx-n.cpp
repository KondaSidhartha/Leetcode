class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        if (x == 1) return 1;
        if (x == -1) {
            if (n % 2 == 0) return 1;
            else return -1;
        }
        if (n == INT_MIN) return 0;
        if(n<0){
            x=1/x;
            n=-1*n;
        }
        while(n>0){
            if(n&1){
                ans*=x;
            }
            x=x*x;
            n>>=1;
        }
        return ans;
    }
};