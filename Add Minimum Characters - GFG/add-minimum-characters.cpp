//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int addMinChar(string s){    
        string rev=s;
        reverse(rev.begin(),rev.end());
        string p=s+"&"+rev;
        
        vector<int> lps(p.size(),0);
        for(int i=1;i<p.size();i++){
             int j=lps[i-1];
             while(j>0 && p[i]!=p[j]){
                 j=lps[j-1];
             }
            lps[i]=(j+=p[i]==p[j]);
        }
        int t=lps[p.size()-1];
        return s.size()-t;
        
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends