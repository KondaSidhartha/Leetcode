//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int num){
        if(num==1)return arr[0];
        int mn=arr[0];
        int mx=arr[0];
        int sum1=arr[0];
        int sum2=arr[0];
        int sum=arr[0];
        int ans=0;
        int mnn=arr[0];
        for(int i=1;i<num;i++){
            mnn=max(mnn,arr[i]);
            sum+=arr[i];
            sum1=min(sum1+arr[i],arr[i]);
            sum2=max(sum2+arr[i],arr[i]);
            mn=min(sum1,mn);
            mx=max(sum2,mx);
        }
        //cout<<mn<<" "<<mx<<" "<<sum<<" ";
        ans=max(mx,sum-mn);
        if(sum==mn)return mx;
        return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends