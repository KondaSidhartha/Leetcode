//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    // bool checkCycle(int node, vector < int > adj[], int vis[], int dfsVis[]) {
    //   vis[node] = 1;
    //   dfsVis[node] = 1;
    //   for (auto it: adj[node]) {
    //     if (!vis[it]) {
    //       if (checkCycle(it, adj, vis, dfsVis)) return true;
    //     } else if (dfsVis[it]) {
    //       return true;
    //     }
    //   }
    //   dfsVis[node] = 0;
    //   return false;
    // }
    bool dfs(int ind,vector<int> & vis,vector<int> &dis,vector<int> adj[]){
        vis[ind]=1;
        dis[ind]=1;
        bool ans=true;
        for(auto it:adj[ind]){
            if(!vis[it]){
                ans=ans&dfs(it,vis,dis,adj);
            }
            else if(dis[it]){
                return false;
            }
        }
        dis[ind]=0;
        return ans;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> dis(V);
        vector<int> vis(V);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,vis,dis,adj)==false){
                    return true;
                }
            }
        }
        return false;
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends