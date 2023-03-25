//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(int i, int j, vector<vector<int>> &mat){
        if(i<0 || i>=mat.size() || j<0 || j>=mat[0].size() || mat[i][j]==0 || mat[i][j]==2)return; 
        mat[i][j]=2;
        //cout<<i<<" "<<j<<endl;
        dfs(i+1,j,mat);
        dfs(i-1,j,mat);
        dfs(i,j+1,mat);
        dfs(i,j-1,mat);
        
    }
    int numberOfEnclaves(vector<vector<int>> &mat) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            if(mat[i][0]==1)dfs(i,0,mat);
            if(mat[i][m-1]==1)dfs(i,m-1,mat);
        }
        for(int i=0;i<m;i++){
            if(mat[0][i]==1)dfs(0,i,mat);
            if(mat[n-1][i]==1)dfs(n-1,i,mat);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1)ans++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends