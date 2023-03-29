//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string s)
    {
        int n=s.size();
        int l=0,k=0;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(islower(s[j]))l++;
                else k++;
                if(l==k)ans++;
            }
            l=0;
            k=0;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends