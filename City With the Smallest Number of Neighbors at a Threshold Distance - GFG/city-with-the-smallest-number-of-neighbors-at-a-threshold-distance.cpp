//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int l, vector<vector<int>>& m,
                 int dt) {
        vector<vector<int>> matrix(n,vector<int>(n,INT_MAX));
			for(auto &it:m){
          matrix[it[0]][it[1]]=it[2];
					matrix[it[1]][it[0]]=it[2];
			}
	    for(int i=0;i<n;i++)matrix[i][i]=0;
	    for(int k=0;k<n;k++){
	        for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
						     if(matrix[i][k]!=INT_MAX && matrix[k][j]!=INT_MAX)
	                matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	        }
	    }
	    }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==1e9)matrix[i][j]=-1;
	        }
	    }
        int ans=0;
        int mn=INT_MAX;
        for(int i=0;i<n;i++){
            int t=0;
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]!=1e9 && matrix[i][j]<=dt){
                    t++;
                }
	        }
            if(t<mn){
                ans=i;
                mn=t;
            }
            else if(t==mn){
                ans=max(ans,i);
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends