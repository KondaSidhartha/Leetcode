class Solution {
public:
    long long mod=7+1e9;
    long long myPow(long long x, long long n) {
        long long ans=1;
        while(n>0){
            if(n&1){
                ans=(ans*x)%mod;
            }
            x=(x*x)%mod;
            n>>=1;
        }
        return ans%mod;
    }
    int countGoodNumbers(long long n) {
        
        return myPow(5,(n+1)/2)%mod*myPow(4,n/2)%mod;
    }
};