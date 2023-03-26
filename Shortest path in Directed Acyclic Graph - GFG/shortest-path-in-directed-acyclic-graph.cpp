//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     void toposort(int node,stack<int> &s,vector<pair<int,int>> adj[],vector<int> &vis){
         vis[node]=1;
         
         for(auto it:adj[node]){
             if(!vis[it.first]){
                 toposort(it.first,s,adj,vis);
             }
         }
         s.push(node);
     }
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        vector<pair<int,int>> adj[n];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> vis(n,0);
        stack<int> s;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                toposort(i,s,adj,vis);
            }
        }
        vector<int> dis(n,1e9);
        dis[0]=0;
        while(!s.empty()){
            int node=s.top();
            s.pop();
            for(auto it:adj[node]){
                int v=it.first;
                int wt=it.second;
                if(dis[node]+wt<dis[v]){
                    dis[v]=dis[node]+wt;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dis[i]==1e9)dis[i]=-1;
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends