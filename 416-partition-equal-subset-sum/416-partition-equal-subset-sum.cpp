class Solution {
public:
    bool subsetsum(vector<int>& nums,int sum){
        int n=nums.size();
        int m=sum;
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        for(int i=0;i<m;i++){
            dp[0][i]=false;
        }
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto i:nums)sum+=i;
        if(sum%2==1)return false;
        else{
            return subsetsum(nums,sum/2);
        }
        return false;
    }
};