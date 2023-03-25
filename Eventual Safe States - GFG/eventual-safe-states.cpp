//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool dfs(int i,vector<int> &vis,vector<int> &pathvis, vector<int> adj[],vector<int> &check){
       vis[i]=1;
       pathvis[i]=1;
       check[i]=0;
       for(auto &it:adj[i]){
           if(!vis[it]){
               if(dfs(it,vis,pathvis,adj,check)==true)return true;
           }
           else if(pathvis[it])return true;
       }
       pathvis[i]=0;
       check[i]=1;
       return false;
   }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
         vector<int> vis(V,0);
        vector<int> pathvis(V,0);
        vector<int> check(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,pathvis,adj,check);
            }
        }
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(check[i]==1)ans.push_back(i);
        }
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends