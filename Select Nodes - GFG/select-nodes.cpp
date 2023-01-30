//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int count=0;
  bool dfs(vector<vector<int>> & v,vector<bool> vis,int node){
      vis[node]=true;
      bool select=false;
      for(auto i:v[node]){
          if(vis[i]==false){
              bool isselect=dfs(v,vis,i);
              if(!isselect)select=true;
          }
      }
      if(select)count++;
      return select;
  }
    int countVertex(int N, vector<vector<int>>edges){
        vector<vector<int>> v(N+1);
        for(auto i:edges){
            v[i[0]].push_back(i[1]);
            v[i[1]].push_back(i[0]);
        }
        vector<bool> vis(N+1,false);
        dfs(v,vis,1);
        return count;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends