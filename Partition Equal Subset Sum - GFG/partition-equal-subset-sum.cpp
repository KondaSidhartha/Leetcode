//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> dp;
    int rec(int ind, int arr[],int tar,int n){
        if(tar==0){
            return 1;
        }
        if(ind>=n)return 0;
        if(dp[ind][tar]!=-1)return dp[ind][tar];
        int ans=0;
        ans|=rec(ind+1,arr,tar,n);
        if(tar>=arr[ind]){
            ans|=rec(ind+1,arr,tar-arr[ind],n);
        }
        return dp[ind][tar]=ans;
    }
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2!=0)return 0;
        dp.resize(N+1,vector<int>((sum/2)+1,-1));
        return rec(0,arr,sum/2,N);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends