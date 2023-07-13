//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    void solve(string str, string &ans, int k, int index){
        
        if(index == str.size() || k == 0){
            ans = max(ans, str);
            return;
        }
        
        solve(str, ans, k, index+1);
        for(int i = index + 1; i < str.size(); i++){
            if(str[index] < str[i]){
                swap(str[index], str[i]);
                solve(str, ans, k-1, index+1);
                swap(str[index], str[i]);
            }
        }
    }
    
    string findMaximumNum(string str, int k)
    {
        string ans = "";
        
        solve(str, ans, k, 0);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends