class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        bool dp[n][n];
        memset(dp,false,sizeof dp);
        int ans=0;
        for(int i=0;i<n;i++){
             ans++;
            dp[i][i]=true;
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
               if(s[i]==s[j]){
                   if(j-i==1 || dp[i+1][j-1]){
                       dp[i][j]=true;
                       ans++;
                   }
               }
            }
        }
        return ans;
    }
};