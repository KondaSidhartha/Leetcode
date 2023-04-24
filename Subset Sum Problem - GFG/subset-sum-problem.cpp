//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
int rec(int level,int sum_left,vector<int> &arr,vector<vector<int>> &dp){
    if(level==arr.size()){
        if(sum_left==0)return 1;
        return 0;
    }
    if(dp[level][sum_left]!=-1)return dp[level][sum_left];
    int ans=rec(level+1,sum_left,arr,dp);

    if (sum_left - arr[level] >= 0) {
      ans = ans+rec(level+1,sum_left-arr[level],arr,dp);
    }
    return dp[level][sum_left]=ans;
}
    bool isSubsetSum(vector<int>arr, int k){
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
    if(rec(0,k,arr,dp))return true;
    else return false;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends