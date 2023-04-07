//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   void dfs(vector<bool> &v,int i,vector<vector<int>>& adj){
        v[i]=true;
        for(auto j:adj[i]){
            if(!v[j]){
                dfs(v,j,adj);
            }
        }
    }
    int Solve(int n, vector<vector<int>>& c) {
         vector<vector<int>> adj(n);
        if(c.size()<n-1)return -1;

        for(auto i:c){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        vector<bool> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(vis,i,adj);
                ans++;
            }
        }
        return ans-1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends