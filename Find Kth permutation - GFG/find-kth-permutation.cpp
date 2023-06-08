//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
       vector<int> v(n+1,false);
        vector<int> fact(n+1,1);
        for(int i = 2; i <= n; i++){
            fact[i] = fact[i-1]*i;
        }
        string ans = "";
        k--;
        for(int i = 1; i <= n; i++){
            int x = k/fact[n-i],j,y=k;
            k -= x*fact[n-i];
            for(j = 1; j <= n; j++){
                if(v[j]==false&&x==0){
                    break;
                }else if(v[j]==false){
                    x--;
                }
            }
            if(j<=n)
            v[j] = true;
            ans = ans + to_string(j);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends