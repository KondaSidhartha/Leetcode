//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisjointSet {
public:
vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
  public:
  bool isValid(int r,int c,int n){
      return r>=0 && r<n && c>=0 && c<n;
  }
    int MaxConnection(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0)continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,-1,0,1};
                for(int ind=0;ind<4;ind++){
                    int newr=dr[ind]+row;
                    int newc=dc[ind]+col;
                    if(isValid(newr,newc,n) && grid[newr][newc]==1){
                        int nodeNo=row*n+col;
                        int adjnodeNo=newr*n+newc;
                        ds.unionBySize(nodeNo,adjnodeNo);
                    }
                }
            }
        }
        int mx=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1)continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,-1,0,1};
                set<int> components;
                for(int ind=0;ind<4;ind++){
                    int newr=dr[ind]+row;
                    int newc=dc[ind]+col;
                    if(isValid(newr,newc,n) && grid[newr][newc]==1){
                        components.insert(ds.findUPar(newr*n+newc));
                    }
                }
                int sizetotal=0;
                for(auto it:components){
                    sizetotal+=ds.size[it];
                }
                mx=max(mx,sizetotal+1);
            }
        }
        for(int cell=0;cell<n*n;cell++){
            mx=max(mx,ds.size[ds.findUPar(cell)]);
        }
        return mx;
        
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends