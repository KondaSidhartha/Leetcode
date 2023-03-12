//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends

string a;
string b;
string c;
int rec(int x,int y,int z,vector<vector<vector<int>>> &dp){
    if(x>=a.size() || y>=b.size() || z>=c.size())return 0;
    
    if(dp[x][y][z]!=-1)return dp[x][y][z];
    
    int ans=0;
    ans=max(ans,rec(x+1,y,z,dp));
    ans=max(ans,rec(x,y+1,z,dp));
    ans=max(ans,rec(x,y,z+1,dp));
    if(a[x]==b[y] && b[y]==c[z]){
        ans=max(ans,1+rec(x+1,y+1,z+1,dp));
    }
    
    return dp[x][y][z]=ans;
}
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    vector<vector<vector<int>>> dp(n1, vector<vector<int>>(n2, vector<int>(n3,-1)));
    a=A;
    b=B;
    c=C;
    return rec(0,0,0,dp);
}