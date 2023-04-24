//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool subsetsum(vector<int>& nums,int sum){
        int n=nums.size();
        int m=sum;
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        for(int i=0;i<m;i++){
            dp[0][i]=false;
        }
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        vector<int> nums;
        for(int i=0;i<N;i++)nums.push_back(arr[i]);
        for(auto i:nums)sum+=i;
        if(sum%2==1)return false;
        else{
            return subsetsum(nums,sum/2);
        }
        return false;
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