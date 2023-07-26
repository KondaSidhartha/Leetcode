//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  long long ans=-1;
  void dfs(int ind,vector<int> &vis,vector<int> adj[],long long sum){
      ans=max(ans,sum);
      vis[ind]=1;
      for(auto it:adj[ind]){
          if(!vis[it]){
              dfs(it,vis,adj,sum+it);
          }
      }
      return;
  }
  long long largestSumCycle(int n, vector<int> e)
  {
     vector<int> adj[n];
     vector<int> indeg(n,0);
     for(int i=0;i<e.size();i++){
         if(e[i]!=-1)adj[i].push_back(e[i]);
         if(e[i]!=-1)indeg[e[i]]++;
     }
     queue<int> q;
     vector<int> vis(n,0);
     for(int i=0;i<n;i++){
         if(indeg[i]==0){
             q.push(i);
         }
     }
     while(!q.empty()){
         auto it=q.front();
        //  cout<<it<<endl;
         q.pop();
         vis[it]=1;
         if(e[it]==-1)continue;
         indeg[e[it]]--;
         if(indeg[e[it]]==0){
             q.push(e[it]);
         }
     }
     for(int i=0;i<n;i++){
         if(!vis[i]){
             dfs(i,vis,adj,i);
         }
     }
     return ans;
  }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends