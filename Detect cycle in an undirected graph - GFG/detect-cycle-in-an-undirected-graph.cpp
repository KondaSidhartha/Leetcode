//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool detectcycle(vector<int> adj[],vector<int> &vis,int i){
        vis[i]=1;
        
        queue<pair<int,int>> q;
        
        q.push({i,-1});
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            for(auto i:adj[t.first]){
                if(!vis[i]){
                    vis[i]=1;
                    q.push({i,t.first});
                }
                else if(t.second!=i)return true;
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> v(V,0);
        for(int i=0;i<V;i++){
            if(!v[i]){
                if(detectcycle(adj,v,i))return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends