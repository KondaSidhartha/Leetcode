//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int solve(int coins[], int n, int m, vector<vector<int>> &dp){
        if(n == 0 || m < 0){
            return 1e9;
        }
        if(m == 0){
            return 0;
        }
        
        if(dp[n][m] != -1){
            return dp[n][m];
        }
        return dp[n][m] = min(solve(coins, n, m-coins[n-1], dp)+1, solve(coins, n-1, m, dp));
        
    }
    
    int minCoins(int coins[], int n, int m) 
    { 
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        int ans = solve(coins, n, m, dp);
        
        if(ans == 1e9){
            return -1;
        }
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends