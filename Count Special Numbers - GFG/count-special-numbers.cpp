//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int n, vector<int> arr) {
        int mx=0;
        for(int i=0;i<n;i++)mx=max(mx,arr[i]);
        int cnt=0;
        vector<int> v(mx+1,0);
        for(int i=0;i<n;i++)v[arr[i]]++;
        for(int i=0;i<n;i++){
            for(int j=1;j<=mx;j++){
                if(v[j] && arr[i]%j==0){
                   cnt++;
                   if(j==arr[i] && v[j]<2)cnt--;
                   break;
                }
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends