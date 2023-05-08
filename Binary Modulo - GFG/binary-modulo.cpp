//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        #define ll long long
        int modulo(string s,int m)
        {
           int n=s.length();
           ll num=0, fac=1;
           for(int i=n-1;i>=0;i--){
               num=(num+(s[i]-'0')*fac)%m;
               fac=(fac*2)%m;
           }
           return num%m;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int m;
        cin>>s>>m;
        Solution a;
        cout<<a.modulo(s,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends