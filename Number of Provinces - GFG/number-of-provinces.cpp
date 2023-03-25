//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    void dfs(vector<int> &vis,int i,vector<int>  adj[]){
        vis[i]=1;
        for(auto j:adj[i]){
            if(!vis[j]){
                dfs(vis,j,adj);
            }
        }
    }
    int numProvinces(vector<vector<int>> v, int n) {
        //int n=v.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    //cout<<i<<" "<<j<<endl;
                }
            }
        }
        int ans=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
           if(!vis[i]){
              // cout<<i<<endl;
               dfs(vis,i,adj);
               ans++;
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
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends