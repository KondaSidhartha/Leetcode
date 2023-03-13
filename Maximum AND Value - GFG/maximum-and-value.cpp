//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function for finding maximum and value pair
	int fun(int patt,int arr[],int n){
	    
	    int cnt=0;
	    for(int i=0;i<n;i++){
	        if((patt&arr[i])==patt)cnt++;
	    }
	    return cnt;
	}
	int maxAND (int arr[], int n)
	{
	    int ans=0;
	    
	    for(int i=31;i>=0;i--){
	        int cnt=fun(ans|(1<<i),arr,n);
	        if(cnt>=2)ans=ans|(1<<i);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
 
// Driver function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        Solution ob;
        cout <<  ob.maxAND(arr,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends