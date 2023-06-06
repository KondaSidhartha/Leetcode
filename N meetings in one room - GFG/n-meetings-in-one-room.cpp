//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int s[], int e[], int n)
    {
        vector<vector<int>> v;
        for(int i=0;i<n;i++){
            v.push_back({e[i],s[i]});
        }
        sort(v.begin(),v.end());
        int ans=0;
        int i=0;
        while(i<n){
            int end=v[i][0];
            int j=i+1;
            while(j<n && v[j][1]<=end){
                j++;
            }
            i=j;
            ans++;
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends