//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        vector<int> temp=arr;
        sort(temp.begin(),temp.end());
        long long sum=0;
        unordered_map<int, long long> mp;
        int prev=0;
        for(auto mem:temp){
            if(mem==prev){
                sum=sum+mem;
            }
            else{
                mp[mem]=sum;
                sum=sum+mem;
                prev=mem;
            }
        }
        vector<long long> ans;
        for(int i=0;i<n;i++){
            ans.push_back(mp[arr[i]]);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends