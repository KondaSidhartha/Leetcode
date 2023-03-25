//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> adjRev[V];
        vector<int> v(V,0);
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]){
	            adjRev[it].push_back(i);
	            v[i]++;
	        }
	    }
	    vector<int> ans;
	    for(int i=0;i<V;i++)if(v[i]==0){q.push(i); ans.push_back(i);}
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        for(auto it:adjRev[node]){
	            v[it]--;
	            if(v[it]==0){q.push(it); ans.push_back(it);}
	        }
	    }
	    sort(ans.begin(),ans.end());
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