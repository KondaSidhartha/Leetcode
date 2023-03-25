//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool bfs(int i,vector<int> &color,vector<int>adj[]){
        queue<int> q;
        q.push(i);
        
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            for(auto j:adj[node]){
                if(color[j]==-1){
                    color[j]=!color[node];
                    q.push(j);
                }
                else if(color[j]==color[node])return false;
            }
        }
        return true;
    } 
	bool isBipartite(int n, vector<int>adj[]){
	    vector<int> color(n,-1);
	    int ans=1;
	    for(int i=0;i<n;i++){
	        if(color[i]==-1){
	            ans=ans&bfs(i,color,adj);
	        }
	    }
	    return ans;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends