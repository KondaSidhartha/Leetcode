class Solution {
public:
    int dp[31][1001]={};
    int numRollsToTarget(int n, int k, int target) {
        if(target<=0 || n==0){
            return n==target;
        }
        if(dp[n][target])return dp[n][target]-1;
        int ans=0;
        for(int i=1;i<=k;i++){
            ans=(ans+numRollsToTarget(n-1,k,target-i))%1000000007;
        }
        dp[n][target]=ans+1;
        return ans%1000000007;
    }
};