//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        vector<int> v1(26,0);
        vector<int> v2(26,0);
     string b="balloon";
     for(char i :b){
         v1[i-'a']++;
     }
     for(char i :s){
         v2[i-'a']++;
     }
     int ans=INT_MAX;
     for(int i=0;i<26;i++){
         if(v1[i]==0)continue;
         ans=min(ans,v2[i]/v1[i]);
     }
     return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends