class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size(),n=s2.size(),N=s3.size();
        if(m+n!=N)return false;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][0]=1;
        //when s1.size()==0, s2==s3
        for(int j=1;j<=n;j++){
            dp[0][j]=(dp[0][j-1] && s2[j-1]==s3[j-1]);
        }
        //when s2.size()==0, s1==s3
        for(int i=1;i<=m;i++){
            dp[i][0]=(dp[i-1][0] && s1[i-1]==s3[i-1]);
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                int k=i+j-1;//index of s3
                dp[i][j]=(dp[i-1][j] && s1[i-1]==s3[k]) || (dp[i][j-1] && s2[j-1]==s3[k]);
            }
        }
        return dp[m][n];
    }
};