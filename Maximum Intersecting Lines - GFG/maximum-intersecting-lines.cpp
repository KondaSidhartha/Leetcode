//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int n) {
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({lines[i][0],0});
            v.push_back({lines[i][1],1});
        }
        sort(v.begin(),v.end());
        int cnt=0;
        int ans=0;
        // for(int i=0;i<n;i++){
        //     cout<<v[i].second<<" ";
        // }
        // cout<<endl;
        for(int i=0;i<2*n;i++){
            if(v[i].second==0)cnt++;
            else cnt--;
            //cout<<cnt<<" ";
            ans=max(ans,cnt);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(2));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < N; i++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxIntersections(mat, N) << endl;
    }
}
// } Driver Code Ends