//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string a)
    {
        int cut[a.length()];
    bool palindrome[a.length()][a.length()];
    memset(palindrome, false, sizeof(palindrome));
    for (int i = 0; i < a.length(); i++)
    {
        int minCut = i;
        for (int j = 0; j <= i; j++)
        {
            if (a[i] == a[j] && (i - j < 2 || palindrome[j + 1][i - 1]))
            {
                palindrome[j][i] = true;
                minCut = min(minCut, j == 0 ? 0 : (cut[j - 1] + 1));
            }
        }
        cut[i] = minCut;
    }
    return cut[a.length() - 1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends