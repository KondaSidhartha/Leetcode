//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int,int>> q;
        q.push({start,0});
        vector<int> dist(100000,1e9);
        dist[start]=0;
        int mod=100000;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int node=it.first;
            int dis=it.second;
            for(auto iter:arr){
                int num=(iter*node)%mod;
                if(dis+1<dist[num]){
                    dist[num]=dis+1;
                    if(num==end)return dis+1;
                    q.push({num,dis+1});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends