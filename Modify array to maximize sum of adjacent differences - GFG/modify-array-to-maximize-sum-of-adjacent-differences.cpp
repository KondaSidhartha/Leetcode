//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{


	public:
	int n;
	int dp[100002][2];
	int rec(int ind,int preone,vector<int> &arr){
	    if(ind>=n)return 0;
	    int ans=INT_MIN;
	    if(dp[ind][preone]!=-1)return dp[ind][preone];
	    if(preone){
	        int pick=abs(arr[ind]-1)+rec(ind+1,0,arr);
	        int npick=rec(ind+1,1,arr);
	        ans=max(pick,npick);
	    }
	    else{
	        int pick=abs(arr[ind]-arr[ind-1])+rec(ind+1,0,arr);
	        int npick=abs(arr[ind-1]-1)+rec(ind+1,1,arr);
	        ans=max(pick,npick);
	    }
	    return dp[ind][preone]=ans;
	}
	int maximumDifferenceSum(int arr[], int N) 
	{ 
	    n=N;
	    memset(dp,-1,sizeof(dp));
	    vector<int> arr1(N);
	    for(int i=0;i<n;i++){
	        arr1[i]=arr[i];
	    }
	    
	    return max(rec(1,0,arr1),rec(1,1,arr1));
	} 


};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.maximumDifferenceSum(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends