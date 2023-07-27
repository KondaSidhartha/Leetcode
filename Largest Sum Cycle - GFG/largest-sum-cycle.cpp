//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
//   void dfs(int ind,vector<int> &vis,vector<int> adj[],long long sum){
//       ans=max(ans,sum);
//       vis[ind]=1;
//       for(auto it:adj[ind]){
//           if(!vis[it]){
//               dfs(it,vis,adj,sum+it);
//           }
//       }
//       return;
//   }
  long long largestSumCycle(int n, vector<int> e)
  {
     vector<int> indeg(n,0);
     for(int i=0;i<e.size();i++){
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
         q.pop();
         vis[it]=1;
         if(e[it]==-1)continue;
         indeg[e[it]]--;
         if(indeg[e[it]]==0){
             q.push(e[it]);
         }
     }
     long long ans=-1;
     for(int i=0;i<n;i++){
         if(vis[i]){
             continue;
            //  dfs(i,vis,adj,i);
         }
         queue<int> qq;
         qq.push(i);
         long long fans=0;
         while(!qq.empty()){
             auto it=qq.front();
             qq.pop();
             vis[it]=1;
             fans+=it;
             if(e[it]==-1)continue;
             if(!vis[e[it]]){
                 qq.push(e[it]);
             }
         }
         ans=max(ans,fans);
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