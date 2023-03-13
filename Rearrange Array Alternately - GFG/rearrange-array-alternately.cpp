//{ Driver Code Starts
// C++ program to rearrange an array in minimum 
// maximum form 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    void rearrange(long long *arr, int n) 
    { 
        for(int i=0;i<n;i++){
            arr[i]=arr[i]<<32;
        }	 
        int i=0;
        int j=n-1;
        int k=0;
        while(k<n){
            arr[k++]|=(arr[j]>>32);
            arr[k++]|=(arr[i]>>32);
            j--;
            i++;
        }
        for(int i=0;i<n;i++){
            arr[i]=arr[i]&(4294967295);
        }
    }
};

//{ Driver Code Starts.

// Driver program to test above function 
int main() 
{
    int t;
    
    //testcases
    cin >> t;
    
    while(t--){
        
        //size of array
        int n;
        cin >> n;
        
        long long arr[n];
        
        //adding elements to the array
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        
        //calling rearrange() function
        ob.rearrange(arr, n);
        
        //printing the elements
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 

// } Driver Code Ends