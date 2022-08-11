class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        bool dp[n][n];
        string ans="";
        memset(dp, false, sizeof(dp) );
        for(int i=0;i<n;i++){
             dp[i][i]=true;
        }
        ans+=s[0];
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j]){
                    if(j-i==1 || dp[i+1][j-1]){
                        dp[i][j]=true;
                        if(ans.size()<j-i+1){
                            ans=s.substr(i,j-i+1);
                        }
                    }
                }
            }
        }
        return ans;
        
    }
};