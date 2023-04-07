//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void dfs(vector<vector<int>>& stones,vector<bool> &vis,int ind){
        vis[ind]=true;
        int a=stones[ind][0];
        int b=stones[ind][1];
        for(int i=0;i<stones.size();i++){
            if(vis[i])continue;
            if(a==stones[i][0] || b==stones[i][1]){
                dfs(stones,vis,i);
            }
        }
    }
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        //int n=stones.size();
        vector<bool> vis(n,false);
        int independent=0;
        for(int i=0;i<n;i++){
            if(vis[i])continue;
            dfs(stones,vis,i);
            independent++;
        }
        return n-independent;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends