//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
public:
    vector<int> dr={1,-1,0,0};
    vector<int> dc={0,0,1,-1};
    
    bool isValid(int i,int j,int n,int m){
        return ((i>=0 && i<n) && (j>=0 && j<m));
    }
    
    void DFS(int i,int j,vector<vector<char>>& grid,int n,int m){
        grid[i][j]='F';
        for(int k=0;k<4;k++){
            int nr=i+dr[k],nc=j+dc[k];
            if(isValid(nr,nc,n,m) && grid[nr][nc]=='O')
                DFS(nr,nc,grid,n,m);
        }
    }
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> grid)
    {
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(grid[i][j]=='O')
                        DFS(i,j,grid,n,m);
                }
            }
        }
        for(auto &it:grid){
            for(auto &gt:it){
                if(gt=='F')
                    gt='O';
                else
                    gt='X';
            }
        }
        return grid;
    }

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends